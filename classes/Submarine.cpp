#ifndef SUBMARINE_CPP
#define SUBMARINE_CPP

#include "Submarine.h"
#include "GlobalConfig.h"
#include "Matrix.h"

void Submarine::KinematicModel()
{
    double dt = GlobalConfig::dt();
    cerr << "dt: " << dt << endl;

    double d_alpha = alpha_dot * dt;
    double d_beta = beta_dot * dt;
    double d_psi = psi_dot * dt;

    alpha += d_alpha;
    beta += d_beta;
    psi += d_psi;

    double c, s;

    c = cos(alpha);
    s = sin(alpha);
    Matrix Rx(4, 4);
    Rx[0] = {1, 0, 0, 0};
    Rx[1] = {0, c, s, 0};
    Rx[2] = {0, -s, c, 0};
    Rx[3] = {0, 0, 0, 1};

    c = cos(beta);
    s = sin(beta);
    Matrix Ry(4, 4);
    Ry[0] = {c, 0, s, 0};
    Ry[1] = {0, 1, 0, 0};
    Ry[2] = {-s, 0, c, 0};
    Ry[3] = {0, 0, 0, 1};

    c = cos(psi);
    s = sin(psi);
    Matrix Rz(4, 4);
    Rz[0] = {c, s, 0, 0};
    Rz[1] = {-s, c, 0, 0};
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

    x += d_u[0][0];
    y += d_u[0][1];
    z += d_u[0][2];
}

void Submarine::beforeDraw()
{
    // centraliza o objeto completamente
    reCenter();

    KinematicModel();

    // posiciona o objeto
    rePosition();

    glColor3f(0, 1, 0);
}

void Submarine::afterDraw()
{
    //cleanControlSignals();
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

const Matrix& Submarine::getDirector() const
{
    return director;
}

void Submarine::rotateLeft(){
    sendControlSignal(0, 0, 0.0872665, 0);
}

void Submarine::rotateRight(){
    beta_dot -= 0.1;
}

#endif // SUBMARINE_CPP