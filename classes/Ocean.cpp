#ifndef OCEAN_CPP
#define OCEAN_CPP

#include <GL/gl.h>
#include <bits/stdc++.h>

#include "Ocean.h"

Ocean::Ocean(){
}

void Ocean::draw(){
    glColor4fv(color_water);
    draw_face(0, 1, 2, 3);
    draw_face(0, 4, 6, 2);
    draw_face(7, 6, 2, 3);
    draw_face(4, 7, 3, 0);
    glColor4fv(color_ground);
    draw_face(4, 5, 6, 7);
}

void Ocean::draw_face(int a, int b, int c, int d){
    glBegin(GL_QUADS);
        glVertex3fv(vertices[a]);
        glVertex3fv(vertices[b]);
        glVertex3fv(vertices[c]);
        glVertex3fv(vertices[d]);
    glEnd();
}

void Ocean::create(){
    color_water = {0.0, 0.0, 1.0, 0.9};
    color_ground = {0.07, 0.57, 0.21, 1.0};
    vertices = {
    {-100, 0, -100},
    {100, 0, -100},
    {100, 0, 100},
    {-100, 0, 100},
    {-100, -100, -100},
    {100, -100, -100},
    {100, -100, 100},
    {-100, -100, 100}
    };
}

#endif // OCEAN_CPP