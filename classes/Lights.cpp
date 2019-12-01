#ifndef LIGHTS_CPP
#define LIGHTS_CPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

#include "Lights.h"

void Lights::create()
{

    on = true;
    smooth = true;

    last_on = false;
    last_smooth = false;

    glShadeModel(GL_SMOOTH);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColorMaterial(GL_FRONT, GL_EMISSION);
    glColorMaterial(GL_FRONT, GL_SHININESS);
    glEnable(GL_COLOR_MATERIAL);

    // Habilita Iluminação
    glEnable(GL_LIGHTING);
}

void Lights::change(bool smooth)
{
    if (last_smooth != smooth)
    {
        this->smooth = !(this->smooth ^ smooth);
    }
    last_smooth = smooth;

    if (this->smooth)
    {
        glShadeModel(GL_SMOOTH);
    }
    else
    {
        glShadeModel(GL_FLAT);
    }
}

void Lights::enable(bool on)
{
    if (last_on != on)
    {
        this->on = !(this->on ^ on);
    }
    last_on = on;

    if (this->on)
    {
        glEnable(GL_LIGHTING);
    }
    else
    {
        glDisable(GL_LIGHTING);
    }
}

#endif // LIGHTS_CPP