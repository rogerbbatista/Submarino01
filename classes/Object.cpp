#ifndef OBJECT_CPP
#define OBJECT_CPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

#include "Object.h"

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

Object::Object() {}

Object::Object(std::string name)
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
    beforeDraw();
    // glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
    for (auto &f : faces)
    {
        glVertex3f(vertices[f.v1].x, vertices[f.v1].y, vertices[f.v1].z);
        glVertex3f(vertices[f.v2].x, vertices[f.v2].y, vertices[f.v2].z);
        glVertex3f(vertices[f.v3].x, vertices[f.v3].y, vertices[f.v3].z);
    }
    glEnd();

    afterDraw();
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

void Object::beforeDraw() {}
void Object::afterDraw() {}

#endif // OBJECT_CPP