#ifndef HELP_H
#define HELP_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

class Help{
    private:
        bool toogled;
        bool last;
    public:
        Help();
        void create();
        void draw();
        void change(bool input);
};

#endif // HELP_H