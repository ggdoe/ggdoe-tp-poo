#include "Equation.h"

// template<class Lambda>
// Equation::Equation(Lambda &&f){
// 	m_f = f;
// }

void Equation::compute(double t, double d_t, Variable &v){
	v(t + d_t) = v(t) + d_t * t;
	/*std::cout << "--- compute equation at time : " << t
			  << " --- value = " << v(t+d_t) << std::endl;*/
}

// template<class Lambda>
// void Equation::compute(double t, double d_t, Variable &v, Lambda &&f){
// 	v(t + d_t) = v(t) + d_t * f(t);
// 	std::cout << "--- compute equation at time : " << t
// 			  << " --- value = " << v(t+d_t) << std::endl;
// }

void Equation::compute_initial_condition(Variable &v){
	v(0) = initial_value;
}

// template<class myIntegrator>
// void Equation::compute_by_integrator(double t, double d_t, Variable &v)
