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

    double d_alpha = alpha_dot * dt;
    double d_beta = beta_dot * dt;
    double d_psi = psi_dot * dt;

    n_alpha = alpha + d_alpha;
    n_beta = beta + d_beta;
    n_psi = psi + d_psi;

    // DEBUG(n_alpha);
    // DEBUG(n_beta);
    // DEBUG(n_psi);

    alignAngles();

    double c, s;

    c = cos(n_alpha);
    s = sin(n_alpha);
    Matrix Rx(4, 4);
    Rx[0] = {1, 0, 0, 0};
    Rx[1] = {0, c, -s, 0};
    Rx[2] = {0, s, c, 0};
    Rx[3] = {0, 0, 0, 1};

    c = cos(n_beta);
    s = sin(n_beta);
    Matrix Ry(4, 4);
    Ry[0] = {c, 0, -s, 0};
    Ry[1] = {0, 1, 0, 0};
    Ry[2] = {s, 0, c, 0};
    Ry[3] = {0, 0, 0, 1};

    c = cos(n_psi);
    s = sin(n_psi);
    Matrix Rz(4, 4);
    Rz[0] = {c, -s, 0, 0};
    Rz[1] = {s, c, 0, 0};
    Rz[2] = {0, 0, 1, 0};
    Rz[3] = {0, 0, 0, 1};

    Matrix R = Rx.dot(Ry.dot(Rz));

    director = Matrix(4, 1);
    director[0][0] = 0;
    director[1][0] = 0;
    director[2][0] = -1;
    director[3][0] = 1;

    director = R.dot(director);

    Matrix d_u = director * u * dt;

    DEBUG(n_x);
    DEBUG(n_y);
    DEBUG(n_z);

    n_x = x + d_u[0][0];
    n_y = y + d_u[0][1];
    n_z = z + d_u[0][2];
}

void Submarine::beforeDraw()
{
    KinematicModel();

    // posiciona o objeto
    rePosition();

    // centraliza o objeto completamente
    reCenter();

    updateValues();

    glColor3f(0, 1, 0);
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
    sendControlSignal(0, 0, 0.1, 0);
}

void Submarine::rotateRight()
{
    sendControlSignal(0, 0, -0.1, 0);
}

void Submarine::walkFront()
{
    sendControlSignal(0.1, 0, 0, 0);
}

void Submarine::walkBack()
{
    sendControlSignal(-0.1, 0, 0, 0);
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