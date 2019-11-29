#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/gl.h>
#include <GL/glut.h>

class Lights{
    private:
        bool on;
        bool smoth;
        
    public:
        void create();
        void enable(bool on);
        void change(bool smooth);
        void turn(bool on, int light);
};

#endif // LIGHTS_H