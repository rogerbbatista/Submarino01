#ifndef HELP_CPP
#define HELP_CPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include "Text.h"

#include "Help.h"

Help::Help(){}

void Help::create(){
    toogled = true;
}

void Help::toogle(){
    toogled = !toogled;
}

void Help::draw(){
    if (toogled){
        int width = glutGet(GLUT_SCREEN_WIDTH);
        int height = glutGet(GLUT_SCREEN_HEIGHT);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();

            glLoadIdentity();
            glOrtho(0.0, width, height, 0.0, -1.0, 10.0);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glDisable(GL_CULL_FACE);

            glClear(GL_DEPTH_BUFFER_BIT);

            glColor3f(1, 1, 1);
            int text_height = height/20;
            int text_padding = (height/2 - text_height*9)/8;
            
            int h = text_height;
            int w = width - width/3 + width/100;
            TEXT::texto("Tecla UP - Inclinar para cima.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla DOWN - Inclinar para baixo.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla 8 - Rotação anti-horária sobre X.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla 2 - Rotação horária sobre X.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla LEFT/A - Rotação anti-horária sobre Y.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla RIGHT/D - Rotação horária sobre Y.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla 4 - Rotação anti-horária sobre Z.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla 6 - Rotação horária sobre Z.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla F - Ponto de vista externo.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla I - Ponto de vista interno.", w, h, 0.2, -0.2);
            h += text_height + text_padding;
            TEXT::texto("Tecla H - Mostrar/Ocultar menu de ajuda.", w, h, 0.2, -0.2);

            glColor3f(0.5, 0.5, 0.5);
            glBegin(GL_QUADS);
                glVertex2f(width - width/3, height*2/3);
                glVertex2f(width , height*2/3);
                glVertex2f(width, 0);
                glVertex2f(width - width/3, 0);
            glEnd();

            glMatrixMode(GL_PROJECTION);

        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
}


#endif // HELP_CPP