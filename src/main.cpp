#include "UniformTimeDiscretization.h"
#include "Equation.h"
#include "Problem.h"
#include "Fabrique.h"
#include "Integrators.h"

#include <cmath>

int main()
{
	Fabrique fb("uniform");
	Problem pb;

	fb.set_initial_value(1.0);

	// fb.set_equation([](double t){ return t;});
	fb.set_equation_diff([](double t, double y){ return cos(y*t*t);});

	pb = fb.get(2.0 * M_PI, 10e4);
	// pb = fb.get(1, 10e5, -1);
	pb.save_in_file("slv-euler.data"); 		// data are saved in /data/ folder
	pb.solve("euler");
	pb.save_in_file("slv-rk4.data"); 		// data are saved in /data/ folder
	pb.solve("rk4"); 
		
	return 0;
}

