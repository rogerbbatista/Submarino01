#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Object.h"
#include "Matrix.h"

class Submarine : public Object
{
private:
    double u;
    double alpha_dot, beta_dot, psi_dot;

    Matrix director;
    
    // virtual functions
    void beforeDraw();
    void afterDraw();

    // non virtual functions
    void cleanControlSignals();

    void KinematicModel();
public:

    Submarine();

    void sendControlSignal(double u, double alpha_dot, double beta_dot, double psi_dot);

    const Matrix& getDirector() const;
};

#endif // SUBMARINE_H