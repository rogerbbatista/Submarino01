#include <GL/gl.h>
#include <GL/glut.h>
#include "classes/Object.h"
#include "classes/Submarine.h"
#include "classes/Ocean.h"
#include "classes/Camera.h"
#include <stdlib.h>

Submarine sub;
Object astronaut[5];
Object coral[5];
Object horse[3];
Object old_ship[2];
Object rocks[2];
Object shark[3];

Ocean ocean;
Camera cam;

void special_handle(int key, int mousex, int mousey)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
    {
        sub.rotateLeft();
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        sub.rotateRight();
        break;
    }
    case GLUT_KEY_UP:
    {
        sub.up();
        break;
    }
    case GLUT_KEY_DOWN:
    {
        sub.down();
        break;
    }
    }
    glutPostRedisplay();
}

void handle(unsigned char key, int mousex, int mousey)
{
    switch (key)
    {
    case 'W':
    case 'w':
    {
        sub.walkFront();
        break;
    }
    case 'S':
    case 's':
    {
        sub.walkBack();
        break;
    }
    case 'F':
    case 'f':
        cam.change_view(false);
        break;
    case 'I':
    case 'i':
        cam.change_view(true);
        break;
    case 'H':
    case 'h':
        break;
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //cor para limpeza do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 200.0);

    sub.charge("submarine");
<<<<<<< HEAD

    for (auto &a: astronaut) a.charge("astronauta");
    astronaut[0].setPosition(0,-35,-85);
    astronaut[1].setPosition(-55,-25,-55);
    astronaut[2].setPosition(0,-15,5);
    astronaut[3].setPosition(55,-20,85);
    astronaut[4].setPosition(75,-30,85);

    for (auto &c: coral) c.charge("coral");
    coral[0].setPosition(-85,-20,-85);
    coral[1].setPosition(85,-20,-25);
    coral[2].setPosition(25,-20,55);
    coral[3].setPosition(-25,-20,55);
    coral[4].setPosition(-45,-20,85);

    for (auto &h: horse) h.charge("horse");
    horse[0].setPosition(-5,-20,-25);
    horse[1].setPosition(-45,-15,35);
    horse[2].setPosition(85,-30,-75);

    for (auto &o: old_ship) o.charge("old_ship");
    old_ship[0].setPosition(10,0,-10);
    old_ship[1].setPosition(0,0,90);

    for (auto &r: rocks) r.charge("rocks");
    rocks[0].setPosition(-45,-20,-85);
    rocks[1].setPosition(85,-20,55);

    for (auto &s: shark) s.charge("shark");
    shark[0].setPosition(-90,-50, 85);
    shark[1].setPosition(35, -70, -65);
    shark[2].setPosition(25, -30, 25);
    
    ocean.create();
=======
    astronaut.charge("astronauta");
    coral.charge("coral");
    horse.charge("horse");
    old_ship.charge("old_ship");
    rocks.charge("rocks");
    shark.charge("shark");

    ocean.create(10);
>>>>>>> 3b71a8c4e2eb119ca8cd43273b26c00c724b312d
    cam.create();

    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a janela
    glLoadIdentity();

    cam.update(sub);

    gluLookAt(cam.getX(), cam.getY(), cam.getZ(),              // define posicao do observador
              cam.lookX(), cam.lookY(), cam.lookZ(),           // ponto de interesse (foco)
              cam.view_upX(), cam.view_upY(), cam.view_upZ()); // vetor de "view up"

    for (auto &a: astronaut) a.draw();
    for (auto &c: coral) c.draw();
    for (auto &h: horse) h.draw();
    for (auto &o: old_ship) o.draw();
    for (auto &r: rocks) r.draw();
    for (auto &s: shark) s.draw();

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
    glutKeyboardFunc(handle);
    glutSpecialFunc(special_handle);
    glutMainLoop();
    return 0;
}
