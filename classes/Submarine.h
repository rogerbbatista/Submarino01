#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Object.h"

class Submarine : public Object
{
private:
    double horizontal_velocity;
    double angular_velocity;
    double vertical_velocity;
    
    // virtual functions
    void beforeDraw();
    void afterDraw();

    // non virtual functions
    void cleanControlSignals();
public:

    Submarine();

    void sendControlSignal(double h_vel, double a_vel, double v_vel);

    

};

#endif // SUBMARINE_H