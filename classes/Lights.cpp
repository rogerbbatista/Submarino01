#ifndef LIGHTS_CPP
#define LIGHTS_CPP

#include <GL/gl.h>
#include <GL/glut.h>

#include "Lights.h"

void Lights::create(){

    bool on = true;
    bool smoth = true;
    bool light0 = true;
    bool light1 = true;

    bool last_on = false;
    bool last_smooth = false;
    bool last_light0 = false;
    bool last_light1 = false;

    // Posição
    GLfloat light_position[ ] = { 1.0, 1.0, 1.0, 0.0 };

    // Quantidade de cor enviada
    GLfloat blue_light[] = { 0, 0, 1.0, 0.0 };
    GLfloat red_light[] = { 1.0, 0, 0, 0.0 };
 
    glClearColor (1.0, 1.0, 1.0, 1.0);

    glShadeModel(GL_SMOOTH);
   
    glEnable(GL_COLOR_MATERIAL) ;
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);

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
    if(last_smooth != smooth)
    {
        this->smooth = !(this->smooth ^ smooth);
    }
    last_smooth = smooth;

    if (this->smooth){
        glShadeModel(GL_SMOOTH);
    }else{
        glShadeModel(GL_FLAT);
    }
}

void Lights::enable(bool on){
    if(last_on != on)
    {
        this->on = !(this->on ^ on);
    }
    last_on = on;

    if (this->on){
        glEnable(GL_LIGHTING);
    }else{
        glDisable(GL_LIGHTING);
    }
}

void Lights::turn(bool on, int light){
    if (light == 0){
        if(last_light0 != on)
        {
            this->light0 = !(this->light0 ^ on);
        }
        last_light0 = on;

        if (this->light0){
            glEnable(GL_LIGHT0);
        }else{
            glDisable(GL_LIGHT0);   
        }
    }else{
        if(last_light1 != on)
        {
            this->light1 = !(this->light1 ^ on);
        }
        last_light1 = on;

        if (this->light1){
            glEnable(GL_LIGHT1);
        }else{
            glDisable(GL_LIGHT1);   
        }
    }
}

#endif // LIGHTS_CPP