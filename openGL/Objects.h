#ifndef OPENGL_OBJ_H
#define OPENGL_OBJ_H

#include "../classes/Object.h"
#include "../classes/Submarine.h"
#include "../classes/Ocean.h"
#include "../classes/Camera.h"
#include "../classes/Lights.h"
#include "../classes/Light.h"
#include "../classes/Help.h"

extern Submarine sub;
extern Object astronaut[5];
extern Object coral[5];
extern Object horse[3];
extern Object old_ship[2];
extern Object rocks[2];
extern Object shark[3];
extern Object ball;

extern Ocean ocean;
extern Camera cam;
extern Lights lights;
extern Help help;

extern Lights lights;
extern Light sun;
extern SpotLight submarine_beacon;
extern SpotLight camera_light;

#endif // OPENGL_OBJ_H