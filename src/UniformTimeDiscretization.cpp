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

double UniformTimeDiscretization::get_pas(double tn){
    return (tmax-tmin)/(size-1);
}