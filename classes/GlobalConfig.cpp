#ifndef GLOBAL_CONFIG_CPP
#define GLOBAL_CONFIG_CPP

#include <bits/stdc++.h>
#include "GlobalConfig.h"

double GlobalConfig::dt() { return 0.1; }
double GlobalConfig::pi() { return M_PI; }

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

#endif //GLOBAL_CONFIG_CPP