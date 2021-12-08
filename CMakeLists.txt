cmake_minimum_required(VERSION 3.10)

project(TP2)

set(CMAKE_CXX_STANDARD 17)

add_executable(out src/main.cpp src/Problem.cpp src/Equation.cpp 
               src/ITimeDiscretization.cpp src/UniformTimeDiscretization.cpp
               src/Fabrique.cpp src/Variable.cpp )

# add_subdirectory(mylib)

# target_include_directories(out PUBLIC mylib)
# target_link_libraries(out PUBLIC mylib)


enable_testing()

find_package(GTest REQUIRED)

add_executable(mytest src/test/test.cpp)
target_include_directories(mytest PUBLIC GTEST_INCLUDE_DIR src/)
target_link_libraries(mytest GTest::GTest GTest::Main)

add_test(test_out out)
gtest_discover_tests(mytest)

