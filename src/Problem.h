#ifndef PROBLEM_H
#define PROBLEM_H

#include "Integrators.h"
#include "Variable.h"
#include "Equation.h"
#include "ITimeDiscretization.h"

class Problem {
	Equation eq;
	ITimeDiscretization *discr;

public:
	Problem(Equation _eq, ITimeDiscretization *_discr);
	~Problem();
	void solve();
};

#endif
