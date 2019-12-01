#include "Functions.h"
#include "Objects.h"

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

    help.change(keyboard.h);
    lights.enable(keyboard.l);
    lights.change(keyboard.g);
    
    sun.enable(keyboard.o);
    camera_light.enable(keyboard.p);

    sub.sendControlSignal(u, alpha_dot, beta_dot, psi_dot, flutuation_dot);

    glutPostRedisplay();

    glutTimerFunc(GConf::tempoAmostragem, mainLoop, 0);
}