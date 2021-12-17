#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

class Timer {
    using clock_type = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock_type> t0, t1;
public:
	Timer() = default;
	void start();
    void stop();
    void print(const std::string &string);
};

#endif
