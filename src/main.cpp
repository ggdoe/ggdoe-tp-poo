#include "UniformTimeDiscretization.h"
#include "Equation.h"
#include "Problem.h"
#include "Fabrique.h"
#include "Integrators.h"


int main()
{
	// UniformTimeDiscretization discr(2, 10);
	// Problem pb(eq, &discr);
	Fabrique fb("uniform");
	fb.set_initial_value(1.0);

	Problem pb = fb.get(1, 100);
	// pb.save_in_file("t.data");
	// pb.solve(); //data are saved in /data/ folder

	// fb.set_equation([](double t){ return t*t;});
	fb.set_equation_diff([](double t, double y){ return y;});
	
	pb = fb.get(1.0, 10e4);
	// pb.save_in_file("tt.data"); 
	pb.solve(); //data are saved in /data/ folder

	// fb.set_equation([](double t, Variable& v){ return 1;});
	// pb = fb.get(1, 100);
	// pb.save_in_file("1.data"); 
	// pb.solve(); //data are saved in /data/ folder
	
	return 0;
}

