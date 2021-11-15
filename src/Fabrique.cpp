#include "Fabrique.h"

Fabrique::Fabrique(const std::string discr_str)
{
	switch(std::tolower(discr_str)){
		// case "uniform":
		// 	choice = Discr_type::UniformDiscr;
		// 	break;
		default :
			choice = Discr_type::UniformDiscr;
			break;

	}
}

Problem Fabrique::get(const Equation &eq)
{
	ITimeDiscretization *_discr;

	switch(choice){
		case Discr_type::UniformDiscr:
			return Problem(eq, new UniformTimeDiscretization());
	}


}