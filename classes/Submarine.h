#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Object.h"
#include "Matrix.h"

class Submarine : public Object
{
private:
    double u;
    double alpha_dot, beta_dot, psi_dot, flutuation_dot;

    // virtual functions
    void beforeDraw();
    void afterDraw();

    // non virtual functions
    void cleanControlSignals();

    void KinematicModel();

    // limits
    double min_weight, max_weight,
        min_height, max_height,
        min_depth, max_depth;

    double min_alpha, max_alpha,
        min_beta, max_beta,
        min_psi, max_psi;

    void correctPosition();

public:
    Submarine();

    void sendControlSignal(double u, double alpha_dot, double beta_dot, double psi_dot, double flutuation_dot);

    void rotateLeft();
    void rotateRight();

    void walkFront();
    void walkBack();

    void up();
    void down();

    void setLimits(double min_weight, double max_weight,
                   double min_height, double max_height,
                   double min_depth, double max_depth);

    void setAngleLimits(double min_alpha, double max_alpha,
                   double min_beta, double max_beta,
                   double min_psi, double max_psi);
};

#endif // SUBMARINE_H