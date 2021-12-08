#ifndef UNIFORMTIMEDISCRETIZATION_H
#define UNIFORMTIMEDISCRETIZATION_H

#include "ITimeDiscretization.h"

class UniformTimeDiscretization : public ITimeDiscretization {
	double pas;
	unsigned int size;
public:
	UniformTimeDiscretization(double _pas, unsigned int _size);
	unsigned int nb_points() override;
	unsigned int iteration(double tn) override;
	double get_pas() override;
};

#endif
