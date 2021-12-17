#include "gtest/gtest.h"
#include "Fabrique.h"
#include <cmath>

#define epsilon 10e-4

TEST(Uniform, Euler_t){
	Fabrique fb("uniform");
	Problem pb;
	pb = fb.get(1, 10e4);
	pb.solve("euler");
	
	const double res = 0.5;
	const double sol = pb.sol;

	// f(0) = 0 ; f'(t) = t ; ==> f(1) = 1/2
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}
TEST(Uniform, Rk4_t){
	Fabrique fb("uniform");
	Problem pb;
	pb = fb.get(1, 10e4);
	pb.solve("rk4");
	
	const double res = 0.5;
	const double sol = pb.sol;

	// f(0) = 0 ; f'(t) = t ; ==> f(1) = 1/2
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}

TEST(Uniform, Euler_exp1){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_initial_value(1.0);
	fb.set_equation_diff([](double t, double y){ return y;});
	pb = fb.get(1, 10e4);
	pb.solve("euler");
	
	const double res = M_E;
	const double sol = pb.sol;

	// f(0) = 1 ; f'(t) = f(t) ; ==> f(1) = e
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}

TEST(Uniform, Rk4_exp1){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_initial_value(1.0);
	fb.set_equation_diff([](double t, double y){ return y;});
	pb = fb.get(1, 10e4);
	pb.solve("rk4");
	
	const double res = M_E;
	const double sol = pb.sol;

	// f(0) = 1 ; f'(t) = f(t) ; ==> f(1) = e
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}

TEST(Uniform, Euler_exp2){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_initial_value(1.0);
	fb.set_equation_diff([](double t, double y){ return exp(t);});
	pb = fb.get(1, 10e4);
	pb.solve("euler");
	
	const double res = M_E;
	const double sol = pb.sol;

	// f(0) = 1 ; f'(t) = exp(t) ; ==> f(1) = e
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}

TEST(Uniform, Rk4_exp2){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_initial_value(1.0);
	fb.set_equation_diff([](double t, double y){ return exp(t);});
	pb = fb.get(1, 10e4);
	pb.solve("rk4");
	
	const double res = M_E;
	const double sol = pb.sol;

	// f(0) = 1 ; f'(t) = exp(t) ; ==> f(1) = e
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}

TEST(Uniform, Euler_cos){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_equation_diff([](double t, double y){ return cos(t);});
	pb = fb.get(2 * M_PI, 10e6);
	pb.solve("euler");
	
	const double res = 0.0;
	const double sol = pb.sol;

	// f(0) = 0 ; f'(t) = cos(t) ; ==> f(2pi) = sin(2pi) = 0
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}

TEST(Uniform, Rk4_cos){
	Fabrique fb("uniform");
	Problem pb;
	fb.set_equation_diff([](double t, double y){ return cos(t);});
	pb = fb.get(2 * M_PI, 10e5);
	pb.solve("rk4");
	
	const double res = 0.0;
	const double sol = pb.sol;

	// f(0) = 0 ; f'(t) = cos(t) ; ==> f(2pi) = sin(2pi) = 0
	ASSERT_TRUE( sol <= res + epsilon && sol >= res - epsilon);
}
