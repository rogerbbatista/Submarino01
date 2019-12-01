#ifndef CAMERA_CPP
#define CAMERA_CPP

#include <GL/gl.h>
#include "Submarine.h"
#include "Matrix.h"
#include "Camera.h"
#include "GConf.h"
#include "../openGL/Objects.h"

Camera::Camera()
{
}

void Camera::create()
{
    view = {0.0, 6.0, 10.0};
    look = {0.0, 0.0, 0.0};
    view_up = {0.0, 1.0, 0.0};
    inside = false;

    std::vector<float> direction(4);
    direction[0] = look[0] - view[0];
    direction[1] = look[1] - view[1];
    direction[2] = look[2] - view[2];
    direction[3] = 1;

    double norm = GConf::norm(direction);

    direction[0] = direction[0] / norm;
    direction[1] = direction[1] / norm;
    direction[2] = direction[2] / norm;

    camera_light.setPosition({view[0], view[1], view[2], 1});
    camera_light.setDirection(direction);
    camera_light.setColor({1, 1, 1, 1});
    camera_light.setAngle(45);
    camera_light.setExponent(0);
    camera_light.create();
}

void Camera::update(Submarine &sub)
{
    Matrix dir = sub.getDirectional();

    if (!inside)
    {
        view = {
            (GLfloat)(sub.getX() - 10 * dir[0][0]),
            (GLfloat)(sub.getY() - 10 * dir[1][0] + 6),
            (GLfloat)(sub.getZ() - 10 * dir[2][0])};

        look = {(GLfloat)sub.getX(),
                (GLfloat)sub.getY(),
                (GLfloat)sub.getZ()};

        view_up = {0.0, 1.0, 0.0};
    }
    else
    {
        Matrix norm = sub.getNormal();

        view = {
            (GLfloat)(sub.getX() + 5 * dir[0][0]),
            (GLfloat)(sub.getY() + 5 * dir[1][0]),
            (GLfloat)(sub.getZ() + 5 * dir[2][0])};

        look = {
            (GLfloat)(sub.getX() + 15 * dir[0][0]),
            (GLfloat)(sub.getY() + 15 * dir[1][0]),
            (GLfloat)(sub.getZ() + 15 * dir[2][0])};

        view_up = {
            (GLfloat)norm[0][0],
            (GLfloat)norm[1][0],
            (GLfloat)norm[2][0]};
    }

    std::vector<float> direction(4);
    direction[0] = look[0] - view[0];
    direction[1] = look[1] - view[1];
    direction[2] = look[2] - view[2];
    direction[3] = 1;

    double norm = GConf::norm(direction);

    direction[0] = direction[0] / norm;
    direction[1] = direction[1] / norm;
    direction[2] = direction[2] / norm;

    camera_light.setPosition({view[0], view[1], view[2], 1});
    camera_light.setDirection(direction);
    camera_light.update();
}

void Camera::change_view(bool ins)
{
    inside = ins;

    if (!inside)
    {
        glEnable(camera_light.getLightId());
    }
    else
    {
        glDisable(camera_light.getLightId());
    }
}

const bool Camera::getInside()
{
    return inside;
}

const GLfloat Camera::getX()
{
    return view[0];
}

const GLfloat Camera::getY()
{
    return view[1];
}

const GLfloat Camera::getZ()
{
    return view[2];
}

const GLfloat Camera::lookX()
{
    return look[0];
}

const GLfloat Camera::lookY()
{
    return look[1];
}

const GLfloat Camera::lookZ()
{
    return look[2];
}

const GLfloat Camera::view_upX()
{
    return view_up[0];
}

const GLfloat Camera::view_upY()
{
    return view_up[1];
}

const GLfloat Camera::view_upZ()
{
    return view_up[2];
}

#endif // CAMERA_CPP