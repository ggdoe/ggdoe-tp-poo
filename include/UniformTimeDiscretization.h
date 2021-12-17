#ifndef UNIFORMTIMEDISCRETIZATION_H
#define UNIFORMTIMEDISCRETIZATION_H

#include "ITimeDiscretization.h"

class UniformTimeDiscretization : public ITimeDiscretization {
	double tmin;
	double tmax;
	unsigned int size;
public:
	UniformTimeDiscretization(double _tmax, unsigned int _size, 
												double _tmin = 0);
	unsigned int nb_points() const override;
	unsigned int iteration(double tn) const override;
	const double get_pas(double tn) const override;
	const double get_min() const override;
};

#endif
