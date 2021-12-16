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
        v(t+d_t) = v(t) + d_t * f(t, v);
    }
};

class RungeKuttaIntegrator {
public:
    RungeKuttaIntegrator() = delete;
    ~RungeKuttaIntegrator() = delete;

    template<class Lambda>
    static void update(double t, double d_t, Variable &v, Lambda &&f){
        double k1, k2, k3, k4, tmp = v(t);
        
        // ne marche pas
        k1 = f(t, v);
        v(t) += d_t*k1/2;
        k2 = f(t + d_t/2, v); 
        v(t) = tmp; v(t) += d_t*k2/2;
        k3 = f(t + d_t/2, v); 
        v(t) = tmp; v(t) += d_t * k3;
        k4 = f(t + d_t, v); 

        v(t) = tmp;
        v(t+d_t) = v(t) + d_t/6 * (k1 + 2*k2 + 2*k3 + k4); 
        // v(t+d_t) = v(t) + d_t * f(t + d_t/2, v); 
    }
};

#endif
