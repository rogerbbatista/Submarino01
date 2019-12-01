#ifndef OCEAN_H
#define OCEAN_H

#include <GL/gl.h>
#include <bits/stdc++.h>
#include "Object.h"

class Ocean
{
private:
    std::vector<GLfloat> color_water;
    std::vector<GLfloat> color_ground;
    std::vector< std::vector<GLfloat> > vertices;
    std::vector<Object> water;
    int second;

public:
    Ocean();
    void draw();
    void draw_water();
    void draw_face(int a, int b, int c, int d);
    void create(double tamanho);
};

#endif // OCEAN_H