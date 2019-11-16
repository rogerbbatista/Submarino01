#include <GL/gl.h>
#include <GL/glut.h>
#include "classes/Object.h"
#include "classes/Submarine.h"
#include "classes/Ocean.h"
#include "classes/Camera.h"
#include <stdlib.h>

Submarine sub;
Object astronaut;
Object coral;
Object horse;
Object old_ship;
Object rocks;
Object shark;

Ocean ocean;
Camera cam;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //cor para limpeza do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 200.0);

    sub.charge("submarine");
    astronaut.charge("astronauta");
    coral.charge("coral");
    horse.charge("horse");
    old_ship.charge("old_ship");
    rocks.charge("rocks");
    shark.charge("shark");
    
    ocean.create();
    cam.create();

    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a janela
    glLoadIdentity();

    cam.update(sub);

    gluLookAt(cam.getX(), cam.getY(), cam.getZ(), // define posicao do observador
              cam.lookX(), cam.lookY(), cam.lookZ(),                   // ponto de interesse (foco)
              cam.view_upX(), cam.view_upY(), cam.view_upZ());                  // vetor de "view up"


    sub.draw();

    ocean.draw();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                                       // inicializa a glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);                    // tipo de buffer/cores/profundidade
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT)); // dimensões da janela
    glutInitWindowPosition(0, 0);                                                // posicao da janela
    glutCreateWindow("Submarino");                                               // cria a janela
    init();
    glutDisplayFunc(display);                          // determina funçãoo callback de desenho
    glEnable(GL_DEPTH_TEST);                           // habilita remoção de superfícies ocultas
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // habilita transparencia
    glEnable(GL_BLEND);                                // hablita transparência
    glutMainLoop();
    return 0;
}
