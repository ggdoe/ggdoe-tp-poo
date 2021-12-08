#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "Variable.h"

class Integrator {
    Integrator() = delete;
    ~Integrator() = delete;
    static void update(double t, double d_t, Variable &v);
};

#endif
