#ifndef HELP_CPP
#define HELP_CPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include "Text.h"

#include "Help.h"

using namespace std;

Help::Help() {}

void Help::create()
{
    toogled = true;
    last = false;
}

void Help::draw()
{
    if (toogled)
    {
        double width = glutGet(GLUT_SCREEN_WIDTH);
        double height = glutGet(GLUT_SCREEN_HEIGHT);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();

        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.0, 10.0);

        // glDisable(GL_LIGHTING);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glDisable(GL_CULL_FACE);

        double scaleFactor = 0.5;

        glScalef(scaleFactor, scaleFactor, 1);

        int n_linhas = 15;

        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        {
            // glVertex2f(width - width/3, height*2/3);
            // glVertex2f(width , height*2/3);
            // glVertex2f(width, 0);
            // glVertex2f(width - width/3, 0);
            glVertex2f(0, 0.8 * max(width, height) * 2 / 3);
            glVertex2f(0.9 * max(width, height) * 2 / 3, 0.8 * max(width, height) * 2 / 3);
            glVertex2f(0.9 * max(width, height) * 2 / 3, 0);
            glVertex2f(0, 0);
        }
        glEnd();

        glClear(GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 1, 1);
        double text_height = scaleFactor * height / 20;
        double text_padding = scaleFactor * (height / 2 - text_height * 9) / 8;

        double padding = scaleFactor * min(width, height) / 100;
        
        double h = text_height;
        double w = padding;
        double tam = scaleFactor * 0.2;


        TEXT::texto("Tecla UP - Flutuar.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla DOWN - Mergulhar.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla 8 - Rotacao anti-horária sobre X.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla 2 - Rotacao horaria sobre X.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla LEFT/A - Rotacao anti-horaria sobre Y.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla RIGHT/D - Rotacao horaria sobre Y.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla 4 - Rotacao anti-horaria sobre Z.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla 6 - Rotacao horaria sobre Z.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla F - Ponto de vista externo.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla I - Ponto de vista interno.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla H - Mostrar/Ocultar menu de ajuda.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla L - Habilita/Desabilita iluminação.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla G - Alterna entre shading Flat/Gouraud.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla P - Habilita/Desabilita Luz 1.", w, h, tam, -tam);
        h += text_height + text_padding;
        TEXT::texto("Tecla O - Habilita/Desabilita Luz 2.", w, h, tam, -tam);
        h += text_height + text_padding;

        // glEnable(GL_LIGHTING);

        glMatrixMode(GL_PROJECTION);

        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
}

void Help::change(bool input)
{
    if(last != input)
    {
        toogled = !(toogled ^ input);
    }
    last = input;
}

#endif // HELP_CPP