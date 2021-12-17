#ifndef PROBLEM_H
#define PROBLEM_H

#include "Integrators.h"
#include "Variable.h"
#include "Equation.h"
#include "ITimeDiscretization.h"
#include "Timer.h"

class Problem {
	using My_Integrator = RungeKuttaIntegrator;

	Equation *eq;
	ITimeDiscretization *discr;
	std::string filename;

public:
	Problem(Equation *_eq, ITimeDiscretization *_discr);
	void save_in_file(std::string _filename);
	~Problem();
	void solve(const std::string &integrator = "rk4");
	void solve_parallel();
};

#endif
