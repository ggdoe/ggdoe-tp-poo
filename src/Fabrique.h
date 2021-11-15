#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <string>
#include "Problem.h"
#include "UniformTimeDiscretization.h"
#include "ITimeDiscretization.h"

class Fabrique {
	enum class Discr_type { UniformDiscr };
	Discr_type choice;
public:
	Fabrique(const std::string discr_str);
	Problem get(const Equation &eq);
};

#endif
