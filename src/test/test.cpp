#include "gtest/gtest.h"

#include "Fabrique.h"

TEST(UnitaryTest,ProblemTest){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_initial_value(1.0);
	fb.set_equation([](double t){ return t;});
	pb = fb.get(1, 10e4);
	pb.solve("euler");
}
