#include "UniformTimeDiscretization.h"

UniformTimeDiscretization::UniformTimeDiscretization(double _tmax, 
                                unsigned int _size, double _tmin)
        : size(_size), tmax(_tmax), tmin(_tmin) {
}

unsigned int UniformTimeDiscretization::nb_points(){
    return size;
}

unsigned int UniformTimeDiscretization::iteration(double tn){
    return static_cast<unsigned int>((tn-tmin)/get_pas(tn));
}

const double UniformTimeDiscretization::get_pas(double tn) const{
    return (tmax-tmin)/static_cast<double>(size-1);
}

const double UniformTimeDiscretization::get_min() const{
    return tmin;
}