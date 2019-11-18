#ifndef HELP_H
#define HELP_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

class Help{
    private:
        bool toogled;
    public:
        Help();
        void create();
        void toogle();
        void draw();
};

#endif // HELP_H