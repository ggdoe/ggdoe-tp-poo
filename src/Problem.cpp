#include "Problem.h"

Problem::Problem(Equation _eq, ITimeDiscretization *_discr) : eq(_eq){
	if(_discr)
		discr = _discr;
}

void Problem::solve(){
	Variable v(discr);
	eq.compute_initial_condition(v);

	std::cout << "--- Solve problem ---" << std::endl;

	double t = -discr->get_pas(0);
	for(double i = 0; i < discr->nb_points(); i++){
		t += discr->get_pas(t);
		eq.compute_by_integrator<RungeKuttaIntegrator>(t, discr->get_pas(t), v);
		// eq.compute(t, 0.1, v);
	}
	std::cout << "--- End solve ---" << std::endl;

	v.print_at_time(t);
	// std::cout << v(t) << std::endl;
}

Problem::~Problem(){
	if(!discr)
		delete discr;
}
