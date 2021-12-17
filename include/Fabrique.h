#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <string>
#include "Problem.h"
#include "UniformTimeDiscretization.h"
#include "ITimeDiscretization.h"

class Fabrique {
	enum class Discr_type { UniformDiscr, NonUniformTimeDiscretization };
public:
	Discr_type choice;
	Equation eq;
	
	Fabrique(const std::string &discr_str);
	Problem get(double tmax, unsigned int size, double tmin = 0);

	template<class Lambda>
	void set_equation(Lambda &&f){
		eq.m_f = [&f](double t, double y){return f(t);};
	}
	
	template<class Lambda>
	void set_equation_diff(Lambda &&f){
		eq.m_f = f;
	}
	void set_initial_value(double x0);
};

#endif
