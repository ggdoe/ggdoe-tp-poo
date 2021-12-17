#include "Problem.h"

Problem::Problem(Equation *_eq, ITimeDiscretization *_discr) : eq(_eq){
	if(_discr)
		discr = _discr;
}

Problem::~Problem(){
	if(!discr)
		delete discr;
}

void Problem::save_in_file(std::string _filename){
	filename = _filename; // if filename is empty no save
}

void Problem::solve(){
	Timer timer_boucle, timer_solve;
	timer_solve.start();
	Variable v(discr);
	eq->compute_initial_condition(v);

	std::cout << std::endl << "--- Solve problem ---" << std::endl;

	double t = -discr->get_pas(0); // pour commencer à 0 et finir à tmax
	
	timer_boucle.start();
	for(double i = 0; i < discr->nb_points(); i++){
		t += discr->get_pas(t);
		eq->compute_by_integrator<My_Integrator>(t, discr->get_pas(t), v);
		// eq.compute(t, 0.1, v);
	}
	timer_boucle.stop();
	// std::cout << "--- End solve ---" << std::endl;

	v.print_at_time(t);

	timer_boucle.print("boucle en temps");
	timer_solve.stop();
	timer_solve.print("fct solve");

	// on ne prend pas en compte le temps d'écriture dans le fichier
	if(!filename.empty()) 
		v.print_in_file(filename);
}

void Problem::solve_parallel(){
	Timer timer_boucle, timer_solve;
	timer_solve.start();
	Variable v(discr);
	eq->compute_initial_condition(v);

	std::cout << std::endl << "--- Solve problem ---" << std::endl;

	double t = -discr->get_pas(0); // pour commencer à 0 et finir à tmax
	
	timer_boucle.start();
	for(double i = 0; i < discr->nb_points(); i++){
		t += discr->get_pas(t);
		eq->compute_by_integrator<My_Integrator>(t, discr->get_pas(t), v);
	}
	timer_boucle.stop();
	// std::cout << "--- End solve ---" << std::endl;

	v.print_at_time(t);

	timer_boucle.print("boucle en temps");
	timer_solve.stop();
	timer_solve.print("fct solve");

	// on ne prend pas en compte le temps d'écriture dans le fichier
	if(!filename.empty()) 
		v.print_in_file(filename);
}
