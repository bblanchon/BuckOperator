# The C++ buck operator (or dollar sign operator) to return multiple values
# from a function
#
# A stupid idea of Benoit Blanchon in 2015
# MIT License

project(buck_operator)

add_compile_options(-std=c++11)

add_executable(example 
	example.cpp
	#buck.cpp
	buck.hpp
)

