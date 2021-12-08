#include "UniformTimeDiscretization.h"

UniformTimeDiscretization::UniformTimeDiscretization(double _pas, unsigned int _size)
        : pas(_pas), size(_size) {

}

unsigned int UniformTimeDiscretization::nb_points(){
    return size;
}

unsigned int UniformTimeDiscretization::iteration(double tn){
    return static_cast<unsigned int>(tn/pas);
}

double  UniformTimeDiscretization::get_pas(){
    return pas;
}