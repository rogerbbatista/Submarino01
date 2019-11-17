#ifndef OBJECT_H
#define OBJECT_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

struct Vertex
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

struct Texture
{
    GLfloat t1;
    GLfloat t2;
};

struct Face
{
    int v1;
    int v2;
    int v3;
    int t1;
    int t2;
    int t3;
    int n1;
    int n2;
    int n3;
    
    void reindex();
};

class Object
{
private:
    std::vector<Vertex> vertices;
    std::vector<Texture> textures;
    std::vector<Vertex> normals;
    std::vector<Face> faces;

    virtual void beforeDraw();
    virtual void afterDraw();

protected:
    double x, y, z;
    double alpha, beta, psi;

    double n_x, n_y, n_z;
    double n_alpha, n_beta, n_psi;

    void reCenter();
    void rePosition();
    void alignAngles();
    void updateValues();

public:
    Object();
    Object(std::string name);
    void draw();
    void charge(std::string name);

    double getX();
    double getY();
    double getZ();
};

#endif // OBJECT_H