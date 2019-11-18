#ifndef OBJECT_H
#define OBJECT_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

#include "Matrix.h"

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

    Matrix rotationMatrix;

    double color_red, color_green, color_blue;

protected:
    double x, y, z;
    double alpha, beta, psi;

    double n_x, n_y, n_z;
    double d_alpha, d_beta, d_psi;

    // structure
    double weight, height, depth;
    
    void reCenter();
    void rePosition();
    void alignAngles();
    void updateValues();

public:
    Object();
    Object(std::string name);
    void draw();
    void charge(std::string name);
    void setPosition(GLfloat x, GLfloat y, GLfloat z);
    void updateRotation(double d_alpha, double d_beta, double d_psi);
    void setColor(double red, double green, double blue);
    const Matrix dotRotation(const Matrix &other) const;
    void setStructure(double weight, double height, double depth);

    double getX();
    double getY();
    double getZ();
};

#endif // OBJECT_H