#ifndef PROBLEM_H
#define PROBLEM_H

#include <thread>
#include "Integrators.h"
#include "Variable.h"
#include "Equation.h"
#include "ITimeDiscretization.h"
#include "Timer.h"

class Problem {
	Equation *eq;
	ITimeDiscretization *discr;
	std::string filename;
	std::function<double(double)> f_exact;

public:
	double sol = 0;

	Problem() = default;
	Problem(Equation *_eq, ITimeDiscretization *_discr);
	~Problem();
	void save_in_file(std::string _filename);
	void solve(const std::string &integrator = "rk4");
	void solve_parallel();

	template<class Lambda>
	void set_f_exact(Lambda &&_f_exact){
		f_exact = _f_exact;
	}
};

#endif
