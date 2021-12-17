#include "UniformTimeDiscretization.h"
#include "Equation.h"
#include "Problem.h"
#include "Fabrique.h"
#include "Integrators.h"

#include <cmath>

#define epsilon 10e-9
int main()
{
	Fabrique fb("uniform");
	Problem pb;

	fb.set_initial_value(1.0);

	// fb.set_equation([](double t){ return t;});
	fb.set_equation_diff([](double t, double y){ return cos(y*t*t);});
	// fb.set_equation_diff([](double t, double y){ return y;});

	pb = fb.get(2.0 * M_PI, 10e4);
	// pb = fb.get(1, 10e4);
	
	pb.save_in_file("edo-euler.data"); 		// file are saved in /data/ folder
	pb.solve("euler");

	pb.save_in_file("edo-rk4.data"); 		// file are saved in /data/ folder
	pb.solve("rk4"); 

	fb.set_equation([](double t){ return t;});
	pb.save_in_file(".data"); // file save in data/ euler.data && rk4.data
	
	pb.set_f_exact([](double t){ return t*t/2;});
	pb.solve_parallel();

	return 0;
}

