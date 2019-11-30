#include <GL/gl.h>
#include <GL/glut.h>
#include "classes/Object.h"
#include "classes/Submarine.h"
#include "classes/Ocean.h"
#include "classes/Camera.h"
#include "classes/Help.h"
#include "classes/Lights.h"
#include "classes/GConf.h"
#include "openGL/Objects.h"
#include "openGL/Functions.h"
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(x) cerr << #x << ": " << x << endl
#endif

// declared as extern in "openGL/functions.h"
Keyboard keyboard;

// declared as extern in "openGL/objects.h"
Submarine sub;
Object astronaut[5];
Object coral[5];
Object horse[3];
Object old_ship[2];
Object rocks[2];
Object shark[3];

Ocean ocean;
Camera cam;
Help help;

//lights
Lights lights;
Light sun(3);
SpotLight submarine_beacon(4);

const double pi = M_PI;

int main(int argc, char **argv)
{
    // inicializa a glut
    glutInit(&argc, argv);

    // tipo de buffer/cores/profundidade
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // dimensões da janela
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    
    // posicao da janela
    glutInitWindowPosition(0, 0);
    
    // cria a janela
    glutCreateWindow("Submarino");
    
    init();
    
    // determina função callback de desenho
    glutDisplayFunc(display);                          
    
    // habilita remoção de superfícies ocultas
    glEnable(GL_DEPTH_TEST);                           
    
    // habilita transparencia
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    
    // hablita transparência
    glEnable(GL_BLEND);                                
    
    // define a calback function para abaixar e levantar tecla
    glutKeyboardFunc(handle);
    glutKeyboardUpFunc(handle);
    glutSpecialFunc(special_handle);
    glutSpecialUpFunc(special_handle);
    
    // define a função de callback da main
    glutTimerFunc(GConf::tempoAmostragem, mainLoop, 0);
    
    glutMainLoop();
    
    return 0;
}
