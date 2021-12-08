#ifndef VARIABLE_H
#define VARIABLE_H

#include "ITimeDiscretization.h"
#include <vector>


class Variable {
	std::vector<double> xn;
    ITimeDiscretization *discr;

public:
	Variable(ITimeDiscretization *_discr);
    double& operator()(double t_n);
};

#endif
