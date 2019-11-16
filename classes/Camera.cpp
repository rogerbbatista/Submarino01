#ifndef CAMERA_CPP
#define CAMERA_CPP

#include <GL/gl.h>
#include "Submarine.h"
#include "Matrix.h"

#include "Camera.h"

Camera::Camera(){
}

void Camera::create(){
    view = {0.0, 6.0, 10.0};
    look = {0.0, 0.0, 0.0};
    view_up = {0.0, 1.0, 0.0};
    inside = false;
}

void Camera::update(Submarine &sub){
    if (!inside){
        view = {(GLfloat)sub.getX(), (GLfloat)sub.getY() + 6 , (GLfloat)sub.getZ() + 10 };
        look = {(GLfloat)sub.getX(), (GLfloat)sub.getY(), (GLfloat)sub.getZ()};
    }else{
        Matrix dir = sub.getDirector();
        view = {(GLfloat)sub.getX(), (GLfloat)sub.getY(), (GLfloat)sub.getZ()};
        look = {(GLfloat)dir[0][0] + 5,
                (GLfloat)dir[1][0],
                (GLfloat)dir[2][0] + 5};
    }
}

void Camera::change_view(){
    inside = !inside;
}

const bool Camera::getInside(){
    return inside;
}

const GLfloat Camera::getX(){
    return view[0];
}

const GLfloat Camera::getY(){
    return view[1];
}

const GLfloat Camera::getZ(){
    return view[2];
}

const GLfloat Camera::lookX(){
    return look[0];
}

const GLfloat Camera::lookY(){
    return look[1];
}

const GLfloat Camera::lookZ(){
    return look[2];
}

#endif // CAMERA_CPP