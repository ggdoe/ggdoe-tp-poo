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
	//eq.initial_value = 1.0;

	Problem pb = fb.get(1, 100);
	pb.save_in_file("t.data"); 
	pb.solve(); //data are saved in /data/ folder

	fb.set_equation([](double t){ return t*t;});
	pb = fb.get(1, 100);
	pb.save_in_file("tt.data"); 
	pb.solve(); //data are saved in /data/ folder

	
	return 0;
}
