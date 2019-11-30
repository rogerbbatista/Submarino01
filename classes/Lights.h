#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/gl.h>
#include <GL/glut.h>

class Lights{
    private:
        bool on;
        bool smooth;
        bool light0;
        bool light1;
        
        bool last_on;
        bool last_smooth;
        bool last_light0;
        bool last_light1;
        
    public:
        void create();
        void enable(bool on);
        void change(bool smooth);
        void turn(bool on, int light);
};

#endif // LIGHTS_H