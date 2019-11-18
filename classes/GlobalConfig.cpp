#ifndef GLOBAL_CONFIG_CPP
#define GLOBAL_CONFIG_CPP

#include <bits/stdc++.h>
#include "GlobalConfig.h"

#ifndef DEBUG
#define DEBUG(x) cerr << #x << ": " << x << " "
#endif

double GlobalConfig::dt() { return 0.1; }
double GlobalConfig::pi() { return M_PI; }
int GlobalConfig::tempoAmostragem() { return 100; }

Matrix GlobalConfig::getRotate(double alpha, double beta, double psi)
{
    double c, s;

    c = cos(alpha);
    s = sin(alpha);
    Matrix Rx(4, 4);
    Rx[0] = {1, 0, 0, 0};
    Rx[1] = {0, c, -s, 0};
    Rx[2] = {0, s, c, 0};
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
    Rz[0] = {c, -s, 0, 0};
    Rz[1] = {s, c, 0, 0};
    Rz[2] = {0, 0, 1, 0};
    Rz[3] = {0, 0, 0, 1};

    Matrix R = Rx.dot(Ry.dot(Rz));

    return R;
}

double GlobalConfig::sum(double a, double b)
{
    int precision = 1000;

    int a1 = round(precision * a);
    int b1 = round(precision * b);

    // cerr << endl << "------------" << endl;

    // DEBUG(a);
    // DEBUG(b);

    // DEBUG(a1);
    // DEBUG(b1);

    int c = a1 + b1;

    // DEBUG(c);

    double s = c;

    // DEBUG(s);

    s /= precision;

    // DEBUG(s);

    return s;
}

double GlobalConfig::getRandom()
{
    static std::random_device rd;
    static std::mt19937 g(rd());
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);

    return distribution(g);
}

#endif //GLOBAL_CONFIG_CPP