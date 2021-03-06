#include "Equation.h"

void Equation::compute(double t, double d_t, Variable &v){
	v(t + d_t) = v(t) + d_t * t;
	/*std::cout << "--- compute equation at time : " << t
			  << " --- value = " << v(t+d_t) << std::endl;*/
}
void Equation::compute_initial_condition(Variable &v){
	v.get_first_elem() = initial_value;
}

// template<class Lambda>
// Equation::Equation(Lambda &&f){
// 	m_f = f;
// }

// template<class Lambda>
// void Equation::compute(double t, double d_t, Variable &v, Lambda &&f){
// 	v(t + d_t) = v(t) + d_t * f(t);
// 	std::cout << "--- compute equation at time : " << t
// 			  << " --- value = " << v(t+d_t) << std::endl;
// }

// template<class myIntegrator>
// void Equation::compute_by_integrator(double t, double d_t, Variable &v)
