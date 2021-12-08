#include "Variable.h"
// #include <iostream>

Variable::Variable(ITimeDiscretization *_discr) 
        : discr(_discr), xn(_discr->nb_points()){
    // discr = _discr;
    // std::cout << discr->nb_points();
}

double& Variable::operator()(double t_n){
    return xn[discr->iteration(t_n)];
}
