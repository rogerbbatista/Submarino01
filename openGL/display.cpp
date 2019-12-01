#include "Functions.h"

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
    ball.draw();
    
    sub.draw();

    ocean.draw();

    help.draw();

    glutSwapBuffers();
}