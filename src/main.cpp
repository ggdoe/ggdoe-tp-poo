#include "UniformTimeDiscretization.h"
#include "Equation.h"
#include "Problem.h"

int main()
{
	UniformTimeDiscretization discr(0.1, 10);
	Equation eq;
	Problem pb(eq, &discr);

	pb.solve();
	return 0;
}
