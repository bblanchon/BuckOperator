# The C++ buck operator (or dollar sign operator) to return multiple values
# from a function
#
# A stupid idea of Benoit Blanchon in 2015
# MIT License

cmake_minimum_required(VERSION 3.1)

project(BuckOperator)

add_executable(example 
	buck.hpp
	example.cpp
)

target_compile_features(example 
	PUBLIC
	cxx_rvalue_references
	cxx_variadic_macros 
	cxx_variadic_templates
)
