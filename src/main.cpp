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
	Equation eq([](double t){ return t*t;});
	Problem pb = fb.get(eq, 1, 10);
	pb.solve();
	
	return 0;
}
