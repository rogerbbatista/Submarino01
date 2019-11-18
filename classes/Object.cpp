#ifndef OBJECT_CPP
#define OBJECT_CPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

#include "Object.h"
#include "GlobalConfig.h"

using namespace std;

#ifndef DEBUG
#define DEBUG(x) std::cerr << #x << ": " << x << std::endl
#endif


void Face::reindex()
{
    v1--;
    v2--;
    v3--;
    t1--;
    t2--;
    t3--;
    n1--;
    n2--;
    n3--;
}

void Object::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Object::Object()
{
    x = 0;
    y = 0;
    z = 0;

    alpha = 0;
    beta = 0;
    psi = 0;

    weight = 0;
    height = 0;
    depth = 0;

    rotationMatrix = GlobalConfig::getRotate(0, 0, 0);
}

Object::Object(std::string name) : Object()
{
    std::ifstream file("models/" + name + ".obj");
    if (file.is_open())
    {

        std::string lines;
        // Chega até a lista de vértices
        file >> lines;
        while (lines != "v")
        {
            file.ignore();
            getline(file, lines);
            file >> lines;
        }
        // Lê os vértices
        Vertex v;
        while (lines == "v")
        {
            file >> v.x >> v.y >> v.z;
            vertices.push_back(v);
            file >> lines;
        }
        // Lê as texturas
        Texture t;
        while (lines == "vt")
        {
            file >> t.t1 >> t.t2;
            textures.push_back(t);
            file >> lines;
        }
        // Lê os vértices
        while (lines == "v")
        {
            file >> v.x >> v.y >> v.z;
            normals.push_back(v);
            file >> lines;
        }
        // Chega até a lista de faces
        while (lines != "f")
        {
            file.ignore();
            getline(file, lines);
            file >> lines;
        }
        // Lê as fs
        Face f;
        char c_aux;
        while (file >> f.v1)
        {
            file >> c_aux >> f.t1 >> c_aux >> f.n1;
            file >> f.v2 >> c_aux >> f.t2 >> c_aux >> f.n2;
            file >> f.v3 >> c_aux >> f.t3 >> c_aux >> f.n3;
            f.reindex();
            faces.push_back(f);
            file >> lines;
        }
    }
    else
    {
        printf(("Não é possível abrir: models/" + name + ".obj").c_str());
    }
}

void Object::draw()
{
    glPushMatrix();
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    beforeDraw();

    glColor4f(color_red, color_green, color_blue, 0.9);

    glBegin(GL_TRIANGLES);
    for (auto &f : faces)
    {
        glVertex3f(vertices[f.v1].x, vertices[f.v1].y, vertices[f.v1].z);
        glVertex3f(vertices[f.v2].x, vertices[f.v2].y, vertices[f.v2].z);
        glVertex3f(vertices[f.v3].x, vertices[f.v3].y, vertices[f.v3].z);
    }
    glEnd();

    afterDraw();
    glPopMatrix();
}

void Object::charge(std::string name)
{
    std::ifstream file("models/" + name + ".obj");
    if (file.is_open())
    {

        std::string lines;
        // Chega até a lista de vértices
        file >> lines;
        while (lines != "v")
        {
            file.ignore();
            getline(file, lines);
            file >> lines;
        }
        // Lê os vértices
        Vertex v;
        while (lines == "v")
        {
            file >> v.x >> v.y >> v.z;
            vertices.push_back(v);
            file >> lines;
        }
        // Lê as texturas
        Texture t;
        while (lines == "vt")
        {
            file >> t.t1 >> t.t2;
            textures.push_back(t);
            file >> lines;
        }
        // Lê os vértices
        while (lines == "v")
        {
            file >> v.x >> v.y >> v.z;
            normals.push_back(v);
            file >> lines;
        }
        // Chega até a lista de faces
        while (lines != "f")
        {
            file.ignore();
            getline(file, lines);
            file >> lines;
        }
        // Lê as fs
        Face f;
        char c_aux;
        while (file >> f.v1)
        {
            file >> c_aux >> f.t1 >> c_aux >> f.n1;
            file >> f.v2 >> c_aux >> f.t2 >> c_aux >> f.n2;
            file >> f.v3 >> c_aux >> f.t3 >> c_aux >> f.n3;
            f.reindex();
            faces.push_back(f);
            file >> lines;
        }
    }
    else
    {
        printf(("Não é possível abrir: models/" + name + ".obj").c_str());
    }
}

void Object::beforeDraw() {
    glTranslatef(x, y, z);
    glColor3f(color_red, color_green, color_blue);   
}

void Object::afterDraw() {
    
}

double Object::getX()
{
    return x;
}

double Object::getY()
{
    return y;
}

double Object::getZ()
{
    return z;
}

void Object::reCenter()
{
    double pi = GlobalConfig::pi();

    // DEBUG(-psi * 180 / pi);
    // DEBUG(-beta * 180 / pi);
    // DEBUG(-alpha * 180 / pi);

    // rotaciona para o centro
    // glRotatef(-psi * 180 / pi, 0, 0, 1);
    // glRotatef(-beta * 180 / pi, 0, 1, 0);
    // glRotatef(-alpha * 180 / pi, 1, 0, 0);

    // translada para (0,0,0)
    // glTranslatef(-x, -y, -z);
}

void Object::rePosition()
{
    double pi = GlobalConfig::pi();
    // fazendo ao contrario pelo opengl

    // translada para (0,0,0)
    glTranslatef(x, y, z);

    // DEBUG(x);
    // DEBUG(y);
    // DEBUG(z);
    // DEBUG(alpha);
    // DEBUG(beta);
    // DEBUG(psi);
    
    // rotaciona
    glRotatef(alpha * 180 / pi, 1, 0, 0);
    glRotatef(beta * 180 / pi, 0, 1, 0);
    glRotatef(psi * 180 / pi, 0, 0, 1);

    // cerr << "o erro nao foi aq" << endl;

}

void Object::alignAngles()
{
    double pi = GlobalConfig::pi();

    if(abs(alpha) > pi)
    {
        if(alpha < 0)
        {
            alpha += 2 * pi;
        }
        else
        {
            alpha -= 2 * pi;
        }
    }

    if(abs(beta) > pi)
    {
        if(beta < 0)
        {
            beta += 2 * pi;
        }
        else
        {
            beta -= 2 * pi;
        }
    }

    if(abs(psi) > pi)
    {
        if(psi < 0)
        {
            psi += 2 * pi;
        }
        else
        {
            psi -= 2 * pi;
        }
    }

    
}

void Object::updateValues()
{
    alignAngles();
}

void Object::updateRotation(double d_alpha, double d_beta, double d_psi)
{
    Matrix R = GlobalConfig::getRotate(d_alpha, d_beta, d_psi);
    rotationMatrix = R.dot(rotationMatrix);
}

const Matrix Object::dotRotation(const Matrix &other) const
{
    return rotationMatrix.dot(other);
}

void Object::setColor(double red, double green, double blue)
{
    color_red = red;
    color_green = green;
    color_blue = blue;
}

void Object::setStructure(double weight, double height, double depth)
{
    this->weight = weight;
    this->height = height;
    this->depth = depth;
}

#endif // OBJECT_CPP