#include "Problem.h"

Problem::Problem(Equation _eq, ITimeDiscretization *_discr) : eq(_eq){
	if(!_discr)
		discr = _discr;
}

void Problem::solve(){
	std::cout << "--- Solve problem ---" << std::endl;
	for(int i = 0; i < 5; ++i)
		eq.compute(i);
}

Problem::~Problem(){
	if(!discr)
		delete discr;
}
