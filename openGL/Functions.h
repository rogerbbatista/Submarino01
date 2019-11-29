#ifndef OPENGL_FUNC_H
#define OPENGL_FUNC_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "Objects.h"
#include "../classes/GConf.h"

struct Keyboard
{
    bool w, s, a, d;
    bool f, i;
    bool h;
    bool g, l;
    bool p, o;
    bool up, down, left, right;
    bool np_up, np_down, np_left, np_right;

    Keyboard()
    {
        g = l = true;
        p = o = true;
        w = s = a = d = f = i = h = false;
        up = down = left = right = false;
        np_up = np_down = np_left = np_right = false;
    }
};

extern Keyboard keyboard;

extern void display(void);
extern void special_handle(int key, int mousex, int mousey);
extern void handle(unsigned char key, int mousex, int mousey);
extern void init(void);
extern void mainLoop(int key);


#endif //OPENGL_FUNC_H
