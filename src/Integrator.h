#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "Variable.h"

class Integrator {
    Integrator() = delete;
    ~Integrator() = delete;
    template<class Lambda>
    static void update(double t, double d_t, Variable &v, Lambda f);
    // pourquoi https://en.cppreference.com/w/cpp/algorithm/remove
    // lambda passé sans référerence ?
};

#endif
