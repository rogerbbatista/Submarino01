#ifndef CAMERA_H
#define CAMERA_H

#include <GL/gl.h>
#include <bits/stdc++.h>
#include "Submarine.h"

class Camera{
    private:
        std::vector<GLfloat> view;
        std::vector<GLfloat> look;
        std::vector<GLfloat> view_up;
        bool inside;
    public:
        Camera();
        void create();
        void update(Submarine &sub);
        void change_view(bool ins);
        const bool getInside();
        const GLfloat getX();
        const GLfloat getY();
        const GLfloat getZ();
        const GLfloat lookX();
        const GLfloat lookY();
        const GLfloat lookZ();
        const GLfloat view_upX();
        const GLfloat view_upY();
        const GLfloat view_upZ();
};

#endif // CAMERA_H