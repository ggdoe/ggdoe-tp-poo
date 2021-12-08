#include "Equation.h"

Equation::Equation(){

}

void Equation::compute(double t, double d_t, Variable &v){
	v(t + d_t) = v(t) + d_t * t;
	std::cout << "--- compute equation at time : " << t
			  << " --- value = " << v(t+d_t) << std::endl;
}

void Equation::compute_initial_condition(Variable &v){
	v(0) = 0;
}