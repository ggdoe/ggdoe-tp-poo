#ifndef VARIABLE_H
#define VARIABLE_H

#include "ITimeDiscretization.h"
#include <vector>
#include <iostream>
#include <fstream>

class Variable {
	std::vector<double> xn;
    ITimeDiscretization *discr;

public:
	Variable(ITimeDiscretization *_discr);
    double& operator()(double t_n);
    void print_at_time(double t_n);
    void print_in_file(std::string filename);
};

#endif
