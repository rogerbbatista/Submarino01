#ifndef LIGHTS_CPP
#define LIGHTS_CPP

#include <GL/gl.h>
#include <GL/glut.h>

#include "Lights.h"

void Lights::create(){

    // Quantidade refletida para cada tipo de reflexão
    GLfloat mat_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 0.0, 1.0, 1.0, 1.0 };

    // Intensificação da luz refletida
    GLfloat mat_shininess[] = { 1.0, 1.0, 1.0, 1.0 };

    // Posição
    GLfloat light_position[ ] = { 1.0, 1.0, 1.0, 0.0 };

    // Quantidade de cor enviada
    GLfloat blue_light[] = { 0, 0, 1.0, 0.0 };
    GLfloat red_light[] = { 1.0, 0, 0, 0.0 };
 
    glClearColor (1.0, 1.0, 1.0, 1.0);
   
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, blue_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, red_light);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, red_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, red_light);

    // Habilita Iluminação
    glEnable(GL_LIGHTING);

    // Habilita Luz 1
    glEnable(GL_LIGHT0);
    // Habilita Luz 2
    glEnable(GL_LIGHT1);
}

void Lights::change(bool smooth){
    if (smooth){
        glShadeModel(GL_SMOOTH);
    }else{
        glShadeModel(GL_FLAT);
    }
}

void Lights::enable(bool on){
    if (on){
        glEnable(GL_LIGHTING);
    }else{
        glDisable(GL_LIGHTING);
    }
}

void Lights::turn(bool on, int light){
    if (on){
        if (light == 0){
            glEnable(GL_LIGHT0);
        }else if (light == 1){
            glEnable(GL_LIGHT1);
        }
    }else{
        if (light == 0){
            glDisable(GL_LIGHT0);
        }else if (light == 1){
            glDisable(GL_LIGHT1);
        }
    }
}

#endif // LIGHTS_CPP