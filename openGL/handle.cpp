#include "Functions.h"

void special_handle(int key, int mousex, int mousey)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
    {
        keyboard.left = !keyboard.left;
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        keyboard.right = !keyboard.right;
        break;
    }
    case GLUT_KEY_UP:
    {
        keyboard.up = !keyboard.up;
        break;
    }
    case GLUT_KEY_DOWN:
    {
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
    case 'L':
    case 'l':
    {
        keyboard.l = !keyboard.l;
        break;
    }
    case 'G':
    case 'g':
    {
        keyboard.g = !keyboard.g;
        break;
    }
    case 'P':
    case 'p':
    {
        keyboard.p = !keyboard.p;
        break;
    }
    case 'O':
    case 'o':
    {
        keyboard.o = !keyboard.o;
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