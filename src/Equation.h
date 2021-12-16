#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include "Integrators.h"
#include <functional>
#include <iostream>

class Equation {
public:
	std::function<double(double)> m_f;
	double initial_value = 0;

	template<class Lambda>
	Equation(Lambda f){
		m_f = f;
	}
	Equation() {
		m_f = [](double t){ return t;};
	}

	void compute(double t, double d_t, Variable &v);
	// template<class Lambda>
	// void compute(double t, double d_t, Variable &v, Lambda &&f);


	template<class myIntegrator>
	void compute_by_integrator(double t, double d_t, Variable &v){
		myIntegrator::update(t, d_t, v, m_f);

		/*std::cout << "--- compute equation at time : " << t
				<< " --- value = " << v(t) << std::endl;*/
	}
	
	void compute_initial_condition(Variable &v);
};

#endif
