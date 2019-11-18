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

    alpha += d_alpha;
    beta += d_beta;
    psi += d_psi;

    // DEBUG(u);
    // DEBUG(alpha_dot);
    // DEBUG(beta_dot);
    // DEBUG(psi_dot);

    alignAngles();

    Matrix R1 = GlobalConfig::getRotate(alpha, beta, psi);
    Matrix R2 = GlobalConfig::getRotate(d_alpha, d_beta, d_psi);
    Matrix R = R2.dot(R1);

    updateRotation(d_alpha, d_beta, d_psi);

    director = Matrix(4, 1);
    director[0][0] = 0;
    director[1][0] = 0;
    director[2][0] = -1;
    director[3][0] = 1;

    // director = dotRotation(director);
    director = R.dot(director);

    Matrix d_u = director * u * dt;

    // alpha = atan2(director[2][0], director[1][0]);
    // beta = atan2(director[0][0], director[2][0]);
    // psi = atan2(director[1][0], director[0][0]);

    // DEBUG(n_x);
    // DEBUG(n_y);
    // DEBUG(n_z);
    // DEBUG(d_u);

    // DEBUG(director);
    // DEBUG(d_u);

    // cout << "----------" << endl;
    // cout << director.T();
    // cout << d_u.T();

    // cout << x << " " << y << " " << z << endl;

    // x = GlobalConfig::sum(x, d_u[0][0]);
    // y = GlobalConfig::sum(y, d_u[1][0]);
    // z = GlobalConfig::sum(z, d_u[2][0]);

    x += d_u[0][0];
    y += d_u[1][0];
    z += d_u[2][0];

    cout << "---------------" << endl;

    cout << x << " " << y << " " << z << endl;

    correctPosition();
    
    cout << x << " " << y << " " << z << endl;
}

void Submarine::beforeDraw()
{
    KinematicModel();

    // Open GL begin

    // translada o objeto pra (0,0,0)
    reCenter();

    // posiciona o objeto
    rePosition();

    // Open GL end

    updateValues();
}

void Submarine::afterDraw()
{

    // cleanControlSignals();
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
    // DEBUG(u);
    // DEBUG(alpha_dot);
    // DEBUG(beta_dot);
    // DEBUG(psi_dot);

    // With inercia
    this->u = (0.85 * this->u) + (0.15 * u);
    this->alpha_dot = (0.85 * this->alpha_dot) + (0.15 * alpha_dot);
    this->beta_dot = (0.85 * this->beta_dot) + (0.15 * beta_dot);
    this->psi_dot = (0.85 * this->psi_dot) + (0.15 * psi_dot);

    // DEBUG(this->u);
    // DEBUG(this->alpha_dot);
    // DEBUG(this->beta_dot);
    // DEBUG(this->psi_dot);
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
    if(x < min_weight + (weight / 2)) x = min_weight + (weight / 2);
    if(x > max_weight - (weight / 2)) x = max_weight - (weight / 2);

    if(y < min_height + (height / 2)) y = min_height + (height / 2);
    if(y > max_height - (height / 2)) y = max_height - (height / 2);

    if(z < min_depth + (depth / 2)) z = min_depth + (depth / 2);
    if(z > max_depth - (depth / 2)) z = max_depth - (depth / 2);

    if(alpha < min_alpha) alpha = min_alpha;
    if(alpha > max_alpha) alpha = max_alpha;

    if(beta < min_beta) beta = min_beta;
    if(beta > max_beta) beta = max_beta;

    if(psi < min_psi) psi = min_psi;
    if(psi > max_psi) psi = max_psi;
}

#endif // SUBMARINE_CPP