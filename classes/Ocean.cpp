#ifndef OCEAN_CPP
#define OCEAN_CPP

#include <GL/gl.h>
#include <bits/stdc++.h>

#include "Ocean.h"

Ocean::Ocean()
{
}

void Ocean::draw()
{
    glColor4f(color_water[0], color_water[1], color_water[2], color_water[3]);
    draw_face(0, 1, 2, 3);
    draw_face(4, 7, 3, 0);
    draw_face(5, 6, 2, 1);
    draw_face(4, 5, 1, 0);
    draw_face(7, 6, 2, 3);
    glColor4f(color_ground[0], color_ground[1], color_ground[2], color_ground[3]);
    draw_face(4, 5, 6, 7);
}

void Ocean::draw_face(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glVertex3f(vertices[a][0], vertices[a][1], vertices[a][2]);
    glVertex3f(vertices[b][0], vertices[b][1], vertices[b][2]);
    glVertex3f(vertices[c][0], vertices[c][1], vertices[c][2]);
    glVertex3f(vertices[d][0], vertices[d][1], vertices[d][2]);
    glEnd();
}

void Ocean::create(int tam)
{
    color_water = {0.0, 0.0, 1.0, 0.8};
    color_ground = {0.07, 0.57, 0.21, 1.0};
    vertices = {
        {-tam, 0, tam},
        {tam, 0, tam},
        {tam, 0, -tam},
        {-tam, 0, -tam},
        {-tam, -tam, tam},
        {tam, -tam, tam},
        {tam, -tam, -tam},
        {-tam, -tam, -tam}};
}

#endif // OCEAN_CPP