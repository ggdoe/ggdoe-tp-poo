#include "Fabrique.h"

Fabrique::Fabrique(const std::string discr_str)
{
	if(discr_str == "gaussian")
		choice = Discr_type::Gaussian;
		// not implemented
	else
		choice = Discr_type::UniformDiscr;
}

Problem Fabrique::get(const Equation &eq)
{
	ITimeDiscretization *_discr;

	switch(choice){
		case Discr_type::UniformDiscr:
			return Problem(eq, new UniformTimeDiscretization());
		case Discr_type::Gaussian:
			// not implemented
			return Problem(eq, new UniformTimeDiscretization());
		default :
			return Problem(eq, new UniformTimeDiscretization());
	}

}