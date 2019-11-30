#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#include <bits/stdc++.h>

#include "Matrix.h"

namespace GConf
{
    // tempo de amostragem
    extern const double dt;
    extern const int tempoAmostragem;
    extern const double pi;

    Matrix getRotate(double alpha, double beta, double psi);
    double sum(double a, double b);
    double getRandom();

} // namespace GlobalConfig

#endif //GLOBAL_CONFIG_H