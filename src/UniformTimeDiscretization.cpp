#include "UniformTimeDiscretization.h"

UniformTimeDiscretization::UniformTimeDiscretization(double _tmax, 
                                unsigned int _size, double _tmin)
        : size(_size), tmax(_tmax), tmin(_tmin) {
}

unsigned int UniformTimeDiscretization::nb_points() const{
    return size;
}

unsigned int UniformTimeDiscretization::iteration(double tn) const{
        // on ajoute 10e-10 pour éviter des problèmes d'arrondi à l'entier
        // ex: pas = 0.010101, t = 0.141414 ==> int(t/pas) = 13 ou 14 ?
    return static_cast<unsigned int>((tn-tmin + 10e-10)/get_pas(tn)); 
    // return static_cast<unsigned int>((tn-tmin)/get_pas(tn));
}

const double UniformTimeDiscretization::get_pas(double tn) const{
    return (tmax-tmin)/static_cast<double>(size-1);
}

const double UniformTimeDiscretization::get_min() const{
    return tmin;
}