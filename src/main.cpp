#include "UniformTimeDiscretization.h"
#include "Equation.h"
#include "Problem.h"

int main()
{
	UniformTimeDiscretization time;
	Equation eq;
	Problem pb(eq, &time);

	pb.solve();
	return 0;
}
