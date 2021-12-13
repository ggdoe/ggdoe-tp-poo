#include "Variable.h"

Variable::Variable(ITimeDiscretization *_discr) 
        : discr(_discr), 
          xn(_discr->nb_points()){
}

double& Variable::operator()(double t_n){
    // const double pas = discr->get_pas(t_n);

    return xn[discr->iteration(t_n)];
}

void Variable::print_at_time(double t_n){
    std::cout << "--- compute equation at time : " << t_n
				<< " --- value = " << (*this)(t_n) << std::endl;
}

void Variable::print_in_file(std::string filename){
    std::ofstream file(filename);

    // for(auto x : xn)
    //     file << 

    double t = -discr->get_pas(0);
	for(double i = 0; i < discr->nb_points(); i++){
		t += discr->get_pas(t);
        file << t << '\t' << xn[i] << std::endl;
	}

    file.close();
}


