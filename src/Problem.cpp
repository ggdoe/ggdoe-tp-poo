#include "Problem.h"

Problem::Problem(Equation _eq, ITimeDiscretization *_discr) : eq(_eq){
	if(_discr)
		discr = _discr;
}

void Problem::solve(){
	Variable v(discr);
	eq.compute_initial_condition(v);

	std::cout << "--- Solve problem ---" << std::endl;

	double t = 0;
	for(double i = 0; i < discr->nb_points(); i++){
		eq.compute(t, 0.1, v);
		t += discr->get_pas();
	}
}

Problem::~Problem(){
	if(!discr)
		delete discr;
}
