#ifndef OBJECT_CPP
#define OBJECT_CPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

#include "Object.h"
#include "GConf.h"

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

    rotationMatrix = GConf::getRotate(0, 0, 0);

    normalVector = Matrix(4, 1);
    normalVector[0][0] = 0;
    normalVector[1][0] = 1;
    normalVector[2][0] = 0;
    normalVector[3][0] = 1;

    directionalVector = Matrix(4, 1);
    directionalVector[0][0] = 0;
    directionalVector[1][0] = 0;
    directionalVector[2][0] = -1;
    directionalVector[3][0] = 1;
}

Object::Object(std::string name) : Object()
{
}

void Object::draw()
{
    glPushMatrix();

    beforeDraw();

    glColor4f(color_red, color_green, color_blue, 0.9);

    GLfloat black[4] = {0,0,0,1};
    glBegin(GL_TRIANGLES);
    for (auto &f : faces)
    {
        // Material m = materials[f.m];
        // if (m.ilu != 0){
        //     if (m.ilu == 2){
        //         glMaterialfv(GL_FRONT, GL_SPECULAR, m.spe);
        //         glMaterialfv(GL_FRONT, GL_EMISSION, m.ems);
        //     }else{
        //         glMaterialfv(GL_FRONT, GL_SPECULAR, black);
        //     }
        //     glMaterialfv(GL_FRONT, GL_AMBIENT, m.amb);
        //     glMaterialfv(GL_FRONT, GL_DIFFUSE, m.dif);
        // }
        // glMaterialf(GL_FRONT, GL_SHININESS, m.shi);

        if (normals.size()) glNormal3f(normals[f.n1].x, normals[f.n1].y, normals[f.n1].z);
        if (textures.size()) glTexCoord2f(textures[f.t1].t1, textures[f.t1].t2);
        glVertex3f(vertices[f.v1].x, vertices[f.v1].y, vertices[f.v1].z);
        if (normals.size()) glNormal3f(normals[f.n2].x, normals[f.n2].y, normals[f.n2].z);
        if (textures.size()) glTexCoord2f(textures[f.t2].t1, textures[f.t2].t2);
        glVertex3f(vertices[f.v2].x, vertices[f.v2].y, vertices[f.v2].z);
        if (normals.size()) glNormal3f(normals[f.n3].x, normals[f.n3].y, normals[f.n3].z);
        if (textures.size()) glTexCoord2f(textures[f.t3].t1, textures[f.t3].t2);
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
        bool next_obj = true;
        std::string lines;
        while (next_obj){
            next_obj = false;

            // Chega até a lista de vértices
            file >> lines;
            while (lines != "v")
            {
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
            while (lines == "vn")
            {
                file >> v.x >> v.y >> v.z;
                normals.push_back(v);
                file >> lines;
            }

            // Procura o material
            while (lines != "usemtl"){
                file >> lines;
            }
            file >> lines;
            if (map_mat.find(lines) == map_mat.end()){
                map_mat[lines] = mat;
                mat++;
                materials.resize(mat);
            }
            int m_num = map_mat[lines];

            // Ignoral linha do 
            while (lines != "f"){
                file >> lines;
            }

            // Lê as fs
            Face f;
            f.m = m_num;
            materials.resize(mat);
            char c_aux;
            while (file >> f.v1)
            {
                file >> c_aux;
                if (textures.size()) file >> f.t1;
                file >> c_aux;
                if (normals.size()) file >> f.n1;

                file >> f.v2;
                file >> c_aux;
                if (textures.size()) file >> f.t2;
                file >> c_aux;
                if (normals.size()) file >> f.n2;

                file >> f.v3;
                file >> c_aux;
                if (textures.size()) file >> f.t3;
                file >> c_aux;
                if (normals.size()) file >> f.n3;

                f.reindex();
                faces.push_back(f);
                file >> lines;
                if (lines == "o"){
                    next_obj = true;
                    break;
                }
            }
        }
    }
    else
    {
        cerr << "Não é possível abrir: models/" + name + ".obj" << endl;
    }

    std::ifstream file2("models/" + name + ".mtl");
    if (file2.is_open())
    {
        std::string lines;
        file2 >> lines;
        // Procura o nome do primeiro material
        while (lines != "newmtl"){
            file2 >> lines;
        }

        Material mat;
        while (true){
            std::string name;
            file2 >> name;
            int m = map_mat[name];

            file2 >> lines;
            file2 >> mat.shi;
            file2 >> lines;
            file2 >> mat.amb[0] >> mat.amb[1] >> mat.amb[2];
            file2 >> lines;
            file2 >> mat.dif[0] >> mat.dif[1] >> mat.dif[2];
            file2 >> lines;
            file2 >> mat.spe[0] >> mat.spe[1] >> mat.spe[2];
            file2 >> lines;
            file2 >> mat.ems[0] >> mat.ems[1] >> mat.ems[2];
            file2 >> lines;
            file2 >> mat.opt;
            file2 >> lines;
            file2 >> mat.alp;
            file2 >> lines;
            file2 >> mat.ilu;

            mat.amb[3] = mat.dif[3] = mat.spe[3] = mat.ems[3] = mat.alp;

            materials[m] = mat;
            file2.ignore();
            if (file2.peek() == EOF){
                break;
            }
            while (lines != "newmtl"){
                file2 >> lines;
            }
        }
        
    }
    else
    {
        cerr << "Não é possível abrir: models/" + name + ".mtl" << endl;
    }
}

void Object::beforeDraw()
{
    rePosition();
}

void Object::afterDraw() {}

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

void Object::reCenter() {}

void Object::rePosition()
{
    double pi = GConf::pi;

    // translada
    glTranslatef(x, y, z);

    // rotaciona
    glRotatef(alpha * 180 / pi, 1, 0, 0);
    glRotatef(beta * 180 / pi, 0, 1, 0);
    glRotatef(psi * 180 / pi, 0, 0, 1);
}

void Object::alignAngles()
{
    double pi = GConf::pi;

    if (abs(alpha) > pi)
    {
        if (alpha < 0)
        {
            alpha += 2 * pi;
        }
        else
        {
            alpha -= 2 * pi;
        }
    }

    if (abs(beta) > pi)
    {
        if (beta < 0)
        {
            beta += 2 * pi;
        }
        else
        {
            beta -= 2 * pi;
        }
    }

    if (abs(psi) > pi)
    {
        if (psi < 0)
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
    Matrix R = GConf::getRotate(d_alpha, d_beta, d_psi);
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

const Matrix& Object::getDirectional() const
{
    return directionalVector;
}

const Matrix& Object::getNormal() const
{
    return normalVector;
}

#endif // OBJECT_CPP