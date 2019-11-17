#ifndef SUBMARINE_CPP
#define SUBMARINE_CPP

#ifndef DEBUG
#define DEBUG(x) cerr << #x << ": " << x << endl
#endif

#include "Submarine.h"
#include "GlobalConfig.h"
#include "Matrix.h"

void Submarine::KinematicModel()
{
    double dt = GlobalConfig::dt();
    double pi = GlobalConfig::pi();

    d_alpha = alpha_dot * dt;
    d_beta = beta_dot * dt;
    d_psi = psi_dot * dt;

    DEBUG(d_alpha);
    DEBUG(d_beta);
    DEBUG(d_psi);

    alignAngles();

    Matrix R1 = GlobalConfig::getRotate(alpha, beta, psi);
    Matrix R2 = GlobalConfig::getRotate(d_alpha, d_beta, d_psi);
    Matrix R = R2.dot(R1);

    director = Matrix(4, 1);
    director[0][0] = 0;
    director[1][0] = 0;
    director[2][0] = -1;
    director[3][0] = 1;

    director = R.dot(director);

    Matrix d_u = director * u * dt;

    // DEBUG(n_x);
    // DEBUG(n_y);
    // DEBUG(n_z);
    // DEBUG(d_u);

    // DEBUG(director);
    // DEBUG(d_u);

    n_x = x + d_u[0][0];
    n_y = y + d_u[0][1];
    n_z = z + d_u[0][2];
}

void Submarine::beforeDraw()
{
    KinematicModel();

    // Open GL begin

    // translada o objeto pra (0,0,0)
    reCenter();
    
    // posiciona o objeto
    rePosition();
    
    glColor3f(0, 1, 0);

    // Open GL end

    updateValues();
}

void Submarine::afterDraw()
{
    cleanControlSignals();
}

Submarine::Submarine()
{
    cleanControlSignals();

    director = Matrix(4, 1);
    director[0][0] = 0;
    director[1][0] = 0;
    director[2][0] = -1;
    director[3][0] = 1;
}

void Submarine::sendControlSignal(double u, double alpha_dot, double beta_dot, double psi_dot)
{
    // Without inercia
    this->u = u;
    this->alpha_dot = alpha_dot;
    this->beta_dot = beta_dot;
    this->psi_dot = psi_dot;
}

void Submarine::cleanControlSignals()
{
    u = 0;
    alpha_dot = 0;
    beta_dot = 0;
    psi_dot = 0;
}

const Matrix &Submarine::getDirector() const
{
    return director;
}

void Submarine::rotateLeft()
{
    sendControlSignal(0, 0, 1, 0);
}

void Submarine::rotateRight()
{
    sendControlSignal(0, 0, -1, 0);
}

void Submarine::walkFront()
{
    sendControlSignal(1, 0, 0, 0);
}

void Submarine::walkBack()
{
    sendControlSignal(-1, 0, 0, 0);
}

void Submarine::up()
{
    sendControlSignal(0, 1, 0, 0);
}

void Submarine::down()
{
    sendControlSignal(0, -1, 0, 0);
}

#endif // SUBMARINE_CPP