#include "UniformTimeDiscretization.h"
#include "Equation.h"
#include "Problem.h"
#include "Fabrique.h"


int main()
{
	// UniformTimeDiscretization discr(2, 10);
	// Problem pb(eq, &discr);

	Fabrique fb("uniform");
	Equation eq;
	Problem pb = fb.get(eq, 1, 10);
	pb.solve();
	return 0;
}
