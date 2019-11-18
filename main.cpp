#include <GL/gl.h>
#include <GL/glut.h>
#include "classes/Object.h"
#include "classes/Submarine.h"
#include "classes/Ocean.h"
#include "classes/Camera.h"
#include "classes/GlobalConfig.h"
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(x) cerr << #x << ": " << x << endl
#endif

struct Keyboard
{
    bool w, s, a, d;
    bool f, i;
    bool h;
    bool up, down, left, right;
    bool np_up, np_down, np_left, np_right;

    Keyboard()
    {
        w = s = a = d = f = i = h = false;
        up = down = left = right = false;
        np_up = np_down = np_left = np_right = false;
    }
};

Keyboard keyboard;

Submarine sub;
Object astronaut[5];
Object coral[5];
Object horse[3];
Object old_ship[2];
Object rocks[2];
Object shark[3];

Ocean ocean;
Camera cam;

const double pi = M_PI;

void special_handle(int key, int mousex, int mousey)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
    {
        // sub.rotateLeft();
        keyboard.left = !keyboard.left;
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        // sub.rotateRight();
        keyboard.right = !keyboard.right;
        break;
    }
    case GLUT_KEY_UP:
    {
        // sub.up();
        keyboard.up = !keyboard.up;
        break;
    }
    case GLUT_KEY_DOWN:
    {
        // sub.down();
        keyboard.down = !keyboard.down;
        break;
    }
    }
}

void handle(unsigned char key, int mousex, int mousey)
{
    switch (key)
    {
    case 'W':
    case 'w':
    {
        keyboard.w = !keyboard.w;
        break;
    }
    case 'S':
    case 's':
    {
        keyboard.s = !keyboard.s;
        break;
    }
    case 'A':
    case 'a':
    {
        keyboard.a = !keyboard.a;
        break;
    }
    case 'D':
    case 'd':
    {
        keyboard.d = !keyboard.d;
        break;
    }
    case 'F':
    case 'f':
    {
        keyboard.f = !keyboard.f;
        break;
    }
    case 'I':
    case 'i':
    {
        keyboard.i = !keyboard.i;
        break;
    }
    case 'H':
    case 'h':
    {
        keyboard.h = !keyboard.h;
        break;
    }
    case '8':
    {
        keyboard.np_up = !keyboard.np_up;
        break;
    }
    case '2':
    {
        keyboard.np_down = !keyboard.np_down;
        break;
    }
    case '4':
    {
        keyboard.np_left = !keyboard.np_left;
        break;
    }
    case '6':
    {
        keyboard.np_right = !keyboard.np_right;
        break;
    }
    }
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //cor para limpeza do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 400.0);

    sub.charge("submarine");
    sub.setColor(0, 1, 0);
    sub.setStructure(5, 5, 8);
    sub.setLimits(-150, 150, -200, 2, -150, 150);
    sub.setAngleLimits(-pi / 6, pi / 6, -pi, pi, -pi / 6, pi / 6);

    for (auto &a : astronaut)
    {
        a.charge("astronauta");
        a.setColor(GlobalConfig::getRandom(), GlobalConfig::getRandom(), GlobalConfig::getRandom());
    }
    astronaut[0].setPosition(0, -35, -85);
    astronaut[1].setPosition(-55, -25, -55);
    astronaut[2].setPosition(0, -15, 5);
    astronaut[3].setPosition(55, -20, 85);
    astronaut[4].setPosition(75, -30, 85);

    for (auto &c : coral)
    {
        c.charge("coral");
        c.setColor(GlobalConfig::getRandom(), GlobalConfig::getRandom(), GlobalConfig::getRandom());
    }
    coral[0].setPosition(-85, -20, -85);
    coral[1].setPosition(85, -20, -25);
    coral[2].setPosition(25, -20, 55);
    coral[3].setPosition(-25, -20, 55);
    coral[4].setPosition(-45, -20, 85);

    for (auto &h : horse)
    {
        h.charge("horse");
        h.setColor(GlobalConfig::getRandom(), GlobalConfig::getRandom(), GlobalConfig::getRandom());
    }
    horse[0].setPosition(-5, -20, -25);
    horse[1].setPosition(-45, -15, 35);
    horse[2].setPosition(85, -30, -75);

    for (auto &o : old_ship)
    {
        o.charge("old_ship");
        o.setColor(GlobalConfig::getRandom(), GlobalConfig::getRandom(), GlobalConfig::getRandom());
    }
    old_ship[0].setPosition(10, 0, -10);
    old_ship[1].setPosition(0, 0, 90);

    for (auto &r : rocks)
    {
        r.charge("rocks");
        r.setColor(GlobalConfig::getRandom(), GlobalConfig::getRandom(), GlobalConfig::getRandom());
    }
    rocks[0].setPosition(-45, -20, -85);
    rocks[1].setPosition(85, -20, 55);

    for (auto &s : shark)
    {
        s.charge("shark");
        s.setColor(GlobalConfig::getRandom(), GlobalConfig::getRandom(), GlobalConfig::getRandom());
    }
    shark[0].setPosition(-90, -50, 85);
    shark[1].setPosition(35, -70, -65);
    shark[2].setPosition(25, -30, 25);

    ocean.create(200);
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

    for (auto &a : astronaut)
        a.draw();
    for (auto &c : coral)
        c.draw();
    for (auto &h : horse)
        h.draw();
    for (auto &o : old_ship)
        o.draw();
    for (auto &r : rocks)
        r.draw();
    for (auto &s : shark)
        s.draw();

    sub.draw();

    ocean.draw();

    glutSwapBuffers();
}

void mainLoop(int key)
{
    double u = 0, alpha_dot = 0, beta_dot = 0, psi_dot = 0, flutuation_dot = 0;

    if (keyboard.w)
        u += 5;
    if (keyboard.s)
        u -= 5;

    if (keyboard.up)
        flutuation_dot += 1;
    if (keyboard.down)
        flutuation_dot -= 1;

    if (keyboard.np_up)
        alpha_dot += 1;
    if (keyboard.np_down)
        alpha_dot -= 1;

    if (keyboard.np_left)
        psi_dot += 1;
    if (keyboard.np_right)
        psi_dot -= 1;

    if (keyboard.left || keyboard.a)
        beta_dot += 1;
    if (keyboard.right || keyboard.d)
        beta_dot -= 1;

    if (keyboard.f)
        cam.change_view(false);
    if (keyboard.i)
        cam.change_view(true);

    sub.sendControlSignal(u, alpha_dot, beta_dot, psi_dot, flutuation_dot);

    glutPostRedisplay();

    glutTimerFunc(GlobalConfig::tempoAmostragem(), mainLoop, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                                       // inicializa a glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);                    // tipo de buffer/cores/profundidade
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT)); // dimensões da janela
    glutInitWindowPosition(0, 0);                                                // posicao da janela
    glutCreateWindow("Submarino");                                               // cria a janela
    init();
    glutDisplayFunc(display);                          // determina funçãoo callback de desenho
    glEnable(GL_DEPTH_TEST);                           // habilita remoção de superfícies ocultas
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // habilita transparencia
    glEnable(GL_BLEND);                                // hablita transparência
    glutKeyboardFunc(handle);
    glutKeyboardUpFunc(handle);
    glutSpecialFunc(special_handle);
    glutSpecialUpFunc(special_handle);
    glutTimerFunc(GlobalConfig::tempoAmostragem(), mainLoop, 0);
    glutMainLoop();
    return 0;
}
