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

void Problem::solve(const std::string &integrator){
	Timer timer_boucle, timer_exact, timer_solve;
	timer_solve.start();

	if(!integrator.empty() && integrator != "euler" && integrator != "rk4")
		std::cout << "### solve(std::string integrator)" << std::endl 
				  << "\tusage : integrator = \"\" or \"euler\" or \"rk4\"" << std::endl
				  << "\t\tdefault : \"rk4\"" << std::endl;

	Variable v(discr);
	eq->compute_initial_condition(v);
	
	std::cout << std::endl << "--- Solve problem" << std::endl;
	if(integrator == "euler")
		std::cout << "---- Methode : Euler" << std::endl;
	else
		std::cout << "---- Methode : RungeKutta" << std::endl;
	
	double t = discr->get_min() - discr->get_pas(0); // pour commencer à 0 et finir à tmax
	
	timer_boucle.start();
	if (integrator == "euler")
		for(double i = 0; i < discr->nb_points(); i++){
			t += discr->get_pas(t);
			eq->compute_by_integrator<EulerIntegrator>(t, discr->get_pas(t), v);
			// v.print_at_time(t);
		}
	else
		for(double i = 0; i < discr->nb_points(); i++){
			t += discr->get_pas(t);
			eq->compute_by_integrator<RungeKuttaIntegrator>(t, discr->get_pas(t), v);
		}
	timer_boucle.stop();
	// std::cout << "--- End solve ---" << std::endl;

	if(f_exact != nullptr){
		timer_exact.start();

		Variable v_exact(discr);
		double t = discr->get_min() - discr->get_pas(0);
		eq->compute_initial_condition(v_exact);
		for(double i = 0; i < discr->nb_points(); i++){
			t += discr->get_pas(t);
			v_exact(t) = eq->initial_value + f_exact(t);
		}
		std::cout << "~~~~~ exact solution at time : " << t << std::endl
				  << "~~~~~ value = " << v_exact(t) << std::endl;
		timer_exact.stop();

		if(!filename.empty()) 
		v_exact.print_in_file(filename);
	}

	v.print_at_time(t);
	sol = v(t);

	timer_boucle.print("boucle en temps");
	timer_solve.stop();
	timer_solve.print("fct solve");
	if(f_exact != nullptr)
		timer_exact.print("Exact");

	// on ne prend pas en compte le temps d'écriture dans le fichier
	if(!filename.empty()) 
		v.print_in_file(filename);
}

void Problem::solve_parallel(){
	Timer timer_euler, timer_rk4, timer_exact, timer_solve;
	timer_solve.start();

	std::cout << std::endl << "--- Solve problem" << std::endl;

	Variable v_euler(discr), v_rk4(discr);
	Variable v_exact(discr);

	std::cout << "---- Start thread Euler" << std::endl;
	std::thread euler_thread([*this, &v_euler, &timer_euler](){
		timer_euler.start();
		double t = discr->get_min() - discr->get_pas(0);
		eq->compute_initial_condition(v_euler);
		for(double i = 0; i < discr->nb_points(); i++){
			t += discr->get_pas(t);
			eq->compute_by_integrator<EulerIntegrator>(t, discr->get_pas(t), v_euler);
		}
		timer_euler.stop();
	});

	std::cout << "---- Start thread RungeKutta" << std::endl;
	std::thread rk4_thread([*this, &v_rk4, &timer_rk4](){
		timer_rk4.start();
		double t = discr->get_min() - discr->get_pas(0);
		eq->compute_initial_condition(v_rk4);
		for(double i = 0; i < discr->nb_points(); i++){
			t += discr->get_pas(t);
			eq->compute_by_integrator<RungeKuttaIntegrator>(t, discr->get_pas(t), v_rk4);
		}
		timer_rk4.stop();
		v_rk4.print_at_time(t);
		// sol = v_rk4(t);
	});

	if(f_exact != nullptr){
		timer_exact.start();
		std::thread exact_thread([*this, &v_exact](){
			double t = discr->get_min() - discr->get_pas(0);
			eq->compute_initial_condition(v_exact);
			for(double i = 0; i < discr->nb_points(); i++){
				t += discr->get_pas(t);
				v_exact(t) = eq->initial_value + f_exact(t);
			}
		std::cout << "~~~~~ exact solution at time : " << t << std::endl
				  << "~~~~~ value = " << v_exact(t) << std::endl;
		});
		exact_thread.join();
		timer_exact.stop();
	}

	euler_thread.join();
	std::cout << "---- Join thread Euler" << std::endl;
	rk4_thread.join();
	std::cout << "---- Join thread RungeKutta" << std::endl;
	// std::cout << "--- End solve ---" << std::endl;

	timer_euler.print("Euler");
	timer_rk4.print("RungeKutta");
	if(f_exact != nullptr)
		timer_exact.print("Exact");

	timer_solve.stop();
	timer_solve.print("fct solve");

	// on ne prend pas en compte le temps d'écriture dans le fichier
	if(!filename.empty()){
		v_euler.print_in_file("euler" + filename);
		v_rk4.print_in_file("rk4" + filename);
		if(f_exact != nullptr)
			v_exact.print_in_file("exact" + filename);
	}
}
