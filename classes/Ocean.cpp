#ifndef OCEAN_CPP
#define OCEAN_CPP

#include <GL/gl.h>
#include <bits/stdc++.h>

#include "Ocean.h"

Ocean::Ocean()
{
    water.resize(2);
}

void Ocean::draw()
{
    glColor4f(color_water[0], color_water[1], color_water[2], 0.8);
    draw_water();
    glColor4f(color_water[0], color_water[1], color_water[2], color_water[3]);
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

void Ocean::draw_water()
{
    glDisable(GL_LIGHTING);
    water[0].setPosition(water[0].getX(), water[0].getY(), water[0].getZ() - 1);
    water[1].setPosition(water[1].getX(), water[1].getY(), water[1].getZ() - 1);
    if (water[second].getZ() == 0){
        second = second ^ 1;
        water[second].setPosition(water[second].getX(), water[second].getY(), 400);
    }
    water[0].draw();
    water[1].draw();
    glEnable(GL_LIGHTING);
}

void Ocean::create(double tamanho)
{
    GLfloat tam = (GLfloat)tamanho;
    color_water = {0.0, 0.0, 1.0, 0.8};
    color_ground = {0.5, 0.5, 0.5, 1.0};
    vertices = {
        {-tam, 0, tam},
        {tam, 0, tam},
        {tam, 0, -tam},
        {-tam, 0, -tam},
        {-tam, -tam, tam},
        {tam, -tam, tam},
        {tam, -tam, -tam},
        {-tam, -tam, -tam}};

    water[0].own_color = true;
    water[1].own_color = true;
    water[0].charge("ocean");
    water[1].charge("ocean");
    water[0].setPosition(0, -1, 400);
    water[1].setPosition(0, -1, 0);
    second = 1;
}

#endif // OCEAN_CPP