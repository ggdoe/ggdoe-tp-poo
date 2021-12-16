#include "Problem.h"

Problem::Problem(Equation *_eq, ITimeDiscretization *_discr) : eq(_eq){
	if(_discr)
		discr = _discr;
}

void Problem::solve(){
	Variable v(discr);
	eq->compute_initial_condition(v);

	std::cout << "--- Solve problem ---" << std::endl;

	double t = -discr->get_pas(0); // pour commencer à 0 et finir à tmax
	for(double i = 0; i < discr->nb_points(); i++){
		t += discr->get_pas(t);
		eq->compute_by_integrator<RungeKuttaIntegrator>(t, discr->get_pas(t), v);
		// eq.compute(t, 0.1, v);
	}
	// std::cout << "--- End solve ---" << std::endl;

	v.print_at_time(t);
	if(!filename.empty())
		v.print_in_file(filename);
	// std::cout << v(t) << std::endl;
}

void Problem::save_in_file(std::string _filename){
	filename = _filename;
}

Problem::~Problem(){
	if(!discr)
		delete discr;
}
