#include "Timer.h"

void Timer::start(){
    t0 = clock_type::now();
}

void Timer::stop(){
    t1 = clock_type::now();
}

void Timer::print(const std::string &string){
    std::chrono::duration<double, std::micro> diff = t1 - t0;
    
    std::cout << "---- chrono \"" << string << "\" : " 
            << diff.count() << "µs"
            << std::endl;
}