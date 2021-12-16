#ifndef ITIMEDISCRETIZATION_H
#define ITIMEDISCRETIZATION_H

class ITimeDiscretization {
public:
	ITimeDiscretization(){};
	virtual ~ITimeDiscretization() = default;
	virtual unsigned int nb_points() = 0;
	virtual unsigned int iteration(double tn) = 0;
	virtual double get_pas(double tn) = 0;
};

#endif
