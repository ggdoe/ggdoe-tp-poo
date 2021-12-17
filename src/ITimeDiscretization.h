#ifndef ITIMEDISCRETIZATION_H
#define ITIMEDISCRETIZATION_H

class ITimeDiscretization {
public:
	ITimeDiscretization() = default;
	virtual ~ITimeDiscretization() = default;
	virtual unsigned int nb_points() = 0;
	virtual unsigned int iteration(double tn) = 0;
	virtual const double get_pas(double tn) const = 0;
	virtual const double get_min() const = 0;
};

#endif
