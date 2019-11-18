#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#include <bits/stdc++.h>

#include "Matrix.h"

namespace GlobalConfig
{
    // tempo de amostragem
    double dt();
    double pi();

    Matrix getRotate(double alpha, double beta, double psi);
    double sum(double a, double b);
    double getRandom();

} // namespace GlobalConfig

#endif //GLOBAL_CONFIG_H