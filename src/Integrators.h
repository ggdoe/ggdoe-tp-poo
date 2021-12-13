#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "Variable.h"

class Integrator {
public:
    Integrator() = delete;
    ~Integrator() = delete;

    template<class Lambda>
    static void update(double t, double d_t, Variable &v, Lambda &&f){}
};

class EulerIntegrator {
public:
    EulerIntegrator() = delete;
    ~EulerIntegrator() = delete;

    template<class Lambda>
    static void update(double t, double d_t, Variable &v, Lambda &&f){
        v(t+d_t) = v(t) + d_t * f(t);
    }
};

class RungeKuttaIntegrator {
public:
    RungeKuttaIntegrator() = delete;
    ~RungeKuttaIntegrator() = delete;

    template<class Lambda>
    static void update(double t, double d_t, Variable &v, Lambda &&f){
        v(t+d_t) = v(t) + d_t * f(t + d_t/2); // f ne depend pas de v
    }
};

#endif
