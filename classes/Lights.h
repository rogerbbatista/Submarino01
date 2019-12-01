#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/gl.h>
#include <GL/glut.h>

class Lights{
    private:
        bool on;
        bool smooth;
        
        bool last_on;
        bool last_smooth;
        
    public:
        void create();
        void enable(bool on);
        void change(bool smooth);
};

#endif // LIGHTS_H