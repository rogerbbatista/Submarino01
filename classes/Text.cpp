#ifndef TEXT_CPP
#define TEXT_CPP

#include <GL/freeglut.h>
#include "Text.h"

void TEXT::texto(const std::string &texto, double x, double y, double tamanhoX, double tamanhoY) {
    glPushMatrix();
        glLoadIdentity();
        glTranslatef(x, y, 0);
        glScalef(tamanhoX, tamanhoY, 1.0);
        for(int i = 0; i < texto.length(); ++i) {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, texto[i]);
        }
    glPopMatrix();
}

#endif // TEXT_CPP