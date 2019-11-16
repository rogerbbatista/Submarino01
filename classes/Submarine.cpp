#ifndef SUBMARINE_CPP
#define SUBMARINE_CPP

#include "Submarine.h"
#include "GlobalConfig.h"

void Submarine::beforeDraw()
{
    // translate to (0, 0, 0)
    glTranslatef(-x, -y, -z);

    // rotate
    double rotation = angular_velocity * GlobalConfig::dt * 180 / GlobalConfig::pi;
    glRotatef(rotation, 0, 0, 1);

    double x_pos = horizontal_velocity * cos(psi) * GlobalConfig::dt;
    double y_pos = horizontal_velocity * sin(psi) * GlobalConfig::dt;
    double z_pos = vertical_velocity * GlobalConfig::dt;

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