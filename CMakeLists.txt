cmake_minimum_required(VERSION 3.16)
project(ODE-Solver)
set(CMAKE_CXX_STANDARD 17)

find_package(Threads)
find_package(GTest REQUIRED)

add_library(lib-odesolver src/Problem.cpp src/Equation.cpp 
               src/UniformTimeDiscretization.cpp src/Fabrique.cpp 
               src/Variable.cpp src/Timer.cpp)

add_executable(odesolver src/main.cpp)

target_include_directories(lib-odesolver PUBLIC include)
target_include_directories(odesolver PUBLIC include)
target_link_libraries(lib-odesolver Threads::Threads)
target_link_libraries(odesolver PUBLIC lib-odesolver)

enable_testing()

add_executable(mygtest src/test/test.cpp)
target_include_directories(mygtest PUBLIC GTEST_INCLUDE_DIR src/)
target_link_libraries(mygtest GTest::GTest GTest::Main lib-odesolver)
add_test(test_solver odesolver)
gtest_discover_tests(mygtest)

