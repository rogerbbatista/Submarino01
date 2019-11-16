#ifndef SUBMARINE_CPP
#define SUBMARINE_CPP

#include "Submarine.h"
#include "GlobalConfig.h"

void Submarine::beforeDraw()
{
    double dt = GlobalConfig::dt();
    double pi = GlobalConfig::pi();
    // translate to (0, 0, 0)
    glTranslatef(-x, -y, -z);

    // rotate
    double rotation = angular_velocity * dt * 180 / pi;
    glRotatef(rotation, 0, 0, 1);

    double x_pos = horizontal_velocity * cos(psi) * dt;
    double y_pos = horizontal_velocity * sin(psi) * dt;
    double z_pos = vertical_velocity * dt;

    glColor3f(0, 1, 0);
}

void Submarine::afterDraw()
{
    cleanControlSignals();
}

Submarine::Submarine()
{
    horizontal_velocity = 0;
    angular_velocity = 0;
    vertical_velocity = 0;
}

void Submarine::sendControlSignal(double h_vel, double a_vel, double v_vel)
{
    // Without inercia
    horizontal_velocity = h_vel;
    angular_velocity = a_vel;
    vertical_velocity = v_vel;
}

void Submarine::cleanControlSignals()
{
    horizontal_velocity = 0;
    angular_velocity = 0;
    vertical_velocity = 0;
}

#endif // SUBMARINE_CPP