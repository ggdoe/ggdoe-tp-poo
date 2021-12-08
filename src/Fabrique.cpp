#include "Fabrique.h"

Fabrique::Fabrique(const std::string discr_str)
{
	if(discr_str == "non_uniform")
		choice = Discr_type::NonUniformTimeDiscretization;
		// not implemented
	else
		choice = Discr_type::UniformDiscr;
}

Problem Fabrique::get(const Equation &eq, double tmax, 
						unsigned int size, double tmin)
{
	switch(choice){
		case Discr_type::NonUniformTimeDiscretization:
			// not implemented
			return Problem(eq, new UniformTimeDiscretization(tmax, size, tmin));
		case Discr_type::UniformDiscr:
		default :
			return Problem(eq, new UniformTimeDiscretization(tmax, size, tmin));
	}

}