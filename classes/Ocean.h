#ifndef OCEAN_H
#define OCEAN_H

#include <GL/gl.h>
#include <bits/stdc++.h>

class Ocean
{
private:
    std::vector<GLfloat> color_water;
    std::vector<GLfloat> color_ground;
    std::vector< std::vector<GLfloat> > vertices;

public:
    Ocean();
    void draw();
    void draw_face(int a, int b, int c, int d);
    void create(int tam);
};

#endif // OCEAN_H