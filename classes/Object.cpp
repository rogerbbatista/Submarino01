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

void Object::setPosition(const GLfloat x, const GLfloat y, const GLfloat z)
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

    n_x = 0;
    n_y = 0;
    n_z = 0;

    n_alpha = 0;
    n_beta = 0;
    n_psi = 0;
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
<<<<<<< HEAD
=======
    // glLoadIdentity();

>>>>>>> 3b71a8c4e2eb119ca8cd43273b26c00c724b312d
    beforeDraw();

    glBegin(GL_TRIANGLES);
    for (auto &f : faces)
    {
        glVertex3f(vertices[f.v1].x, vertices[f.v1].y, vertices[f.v1].z);
        glVertex3f(vertices[f.v2].x, vertices[f.v2].y, vertices[f.v2].z);
        glVertex3f(vertices[f.v3].x, vertices[f.v3].y, vertices[f.v3].z);
    }
    glEnd();

    afterDraw();
<<<<<<< HEAD
=======

>>>>>>> 3b71a8c4e2eb119ca8cd43273b26c00c724b312d
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
    // fazendo ao contrario pelo opengl

    // rotaciona para o centro
    glRotatef(-alpha * 180 / pi, 1, 0, 0);
    glRotatef(-beta * 180 / pi, 0, 1, 0);
    glRotatef(-psi * 180 / pi, 0, 0, 1);

    // translada para (0,0,0)
    glTranslatef(-x, -y, -z);
}

void Object::rePosition()
{
    double pi = GlobalConfig::pi();
    // fazendo ao contrario pelo opengl

    // translada para (0,0,0)
    glTranslatef(n_x, n_y, n_z);

    // DEBUG(n_alpha);
    // DEBUG(n_beta);
    // DEBUG(n_psi);
    
    // rotaciona para o centro
    glRotatef(n_alpha * 180 / pi, 1, 0, 0);
    glRotatef(n_beta * 180 / pi, 0, 1, 0);
    glRotatef(n_psi * 180 / pi, 0, 0, 1);

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

    if(abs(n_alpha) > pi)
    {
        if(n_alpha < 0)
        {
            n_alpha += 2 * pi;
        }
        else
        {
            n_alpha -= 2 * pi;
        }
    }

    if(abs(n_beta) > pi)
    {
        if(n_beta < 0)
        {
            n_beta += 2 * pi;
        }
        else
        {
            n_beta -= 2 * pi;
        }
    }

    if(abs(n_psi) > pi)
    {
        if(n_psi < 0)
        {
            n_psi += 2 * pi;
        }
        else
        {
            n_psi -= 2 * pi;
        }
    }
}

void Object::updateValues()
{
    x = n_x;
    y = n_y;
    z = n_z;

    alpha = n_alpha;
    beta = n_beta;
    psi = n_psi;
}

#endif // OBJECT_CPP