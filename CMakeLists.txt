# CMakeList.txt : CMake project for FizzBuzz, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("FizzBuzz")
set(CMAKE_CXX_STANDARD 20)
# Add source to this project's executable.
add_executable (FizzBuzz "FizzBuzz.cpp")

# TODO: Add tests and install targets if needed.
