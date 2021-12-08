#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include <iostream>

class Equation {

public:
	Equation();
	void compute(double t, double d_t, Variable &v);
	void compute_initial_condition(Variable &v);
};

#endif
