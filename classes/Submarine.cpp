#ifndef SUBMARINE_CPP
#define SUBMARINE_CPP

#ifndef DEBUG
#define DEBUG(x) cerr << #x << ": " << x << endl
#endif

#include "Submarine.h"
#include "GConf.h"
#include "Matrix.h"

void Submarine::KinematicModel()
{
    double dt = GConf::dt;
    double pi = GConf::pi;

    double d_alpha = alpha_dot * dt;
    double d_beta = beta_dot * dt;
    double d_psi = psi_dot * dt;
    double d_flutuation = flutuation_dot * dt;

    alpha += d_alpha;
    beta += d_beta;
    psi += d_psi;

    alignAngles();

    // aplicar no vetor normal
    Matrix R1 = GConf::getRotate(0, 0, psi);

    normalVector = Matrix(4, 1);
    normalVector[0][0] = 0;
    normalVector[1][0] = 1;
    normalVector[2][0] = 0;
    normalVector[3][0] = 1;

    normalVector = R1.dot(normalVector);

    // aplicar no vetor direcional
    Matrix R2 = GConf::getRotate(alpha, beta, 0);

    directionalVector = Matrix(4, 1);
    directionalVector[0][0] = 0;
    directionalVector[1][0] = 0;
    directionalVector[2][0] = -1;
    directionalVector[3][0] = 1;

    directionalVector = R2.dot(directionalVector);

    Matrix d_u = directionalVector * u * dt;

    x += d_u[0][0];
    y += d_u[1][0] + d_flutuation;
    z += d_u[2][0];

    correctPosition();
}

void Submarine::beforeDraw()
{
    KinematicModel();

    // posiciona o objeto
    rePosition();

    updateValues();
}

void Submarine::afterDraw() { }

Submarine::Submarine()
{
    cleanControlSignals();

    directionalVector = Matrix(4, 1);
    directionalVector[0][0] = 0;
    directionalVector[1][0] = 0;
    directionalVector[2][0] = -1;
    directionalVector[3][0] = 1;
}

void Submarine::sendControlSignal(double u, double alpha_dot,
                                  double beta_dot, double psi_dot, double flutuation_dot)
{
    // With inercia
    this->u = (0.9 * this->u) + (0.1 * u);
    this->alpha_dot = (0.9 * this->alpha_dot) + (0.1 * alpha_dot);
    this->beta_dot = (0.9 * this->beta_dot) + (0.1 * beta_dot);
    this->psi_dot = (0.9 * this->psi_dot) + (0.1 * psi_dot);
    this->flutuation_dot = (0.9 * this->flutuation_dot) + (0.1 * flutuation_dot);
}

void Submarine::cleanControlSignals()
{
    u = 0;
    alpha_dot = 0;
    beta_dot = 0;
    psi_dot = 0;
    flutuation_dot = 0;
}

void Submarine::setLimits(double min_weight, double max_weight,
                          double min_height, double max_height,
                          double min_depth, double max_depth)
{
    this->min_weight = min_weight;
    this->max_weight = max_weight;

    this->min_height = min_height;
    this->max_height = max_height;

    this->min_depth = min_depth;
    this->max_depth = max_depth;
}

void Submarine::setAngleLimits(double min_alpha, double max_alpha,
                               double min_beta, double max_beta,
                               double min_psi, double max_psi)
{
    this->min_alpha = min_alpha;
    this->max_alpha = max_alpha;

    this->min_beta = min_beta;
    this->max_beta = max_beta;

    this->min_psi = min_psi;
    this->max_psi = max_psi;
}

void Submarine::correctPosition()
{
    if (x < min_weight + (weight / 2))
        x = min_weight + (weight / 2);
    if (x > max_weight - (weight / 2))
        x = max_weight - (weight / 2);

    if (y < min_height + (height / 2))
        y = min_height + (height / 2);
    if (y > max_height - (height / 2))
        y = max_height - (height / 2);

    if (z < min_depth + (depth / 2))
        z = min_depth + (depth / 2);
    if (z > max_depth - (depth / 2))
        z = max_depth - (depth / 2);

    if (alpha < min_alpha)
        alpha = min_alpha;
    if (alpha > max_alpha)
        alpha = max_alpha;

    if (beta < min_beta)
        beta = min_beta;
    if (beta > max_beta)
        beta = max_beta;

    if (psi < min_psi)
        psi = min_psi;
    if (psi > max_psi)
        psi = max_psi;
}

#endif // SUBMARINE_CPP