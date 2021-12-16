#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <string>
#include "Problem.h"
#include "UniformTimeDiscretization.h"
#include "ITimeDiscretization.h"

class Fabrique {
	enum class Discr_type { UniformDiscr, NonUniformTimeDiscretization };
	Discr_type choice;
	Equation eq;
public:
	Fabrique(const std::string discr_str);
	Problem get(double tmax, unsigned int size, double tmin = 0);
	template<class Lambda>
	void set_equation(Lambda &&f){
		eq.m_f = f;
	}
};

#endif
