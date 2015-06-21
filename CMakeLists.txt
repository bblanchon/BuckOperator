# The C++ buck operator (or dollar sign operator) to return multiple values
# from a function
#
# A stupid idea of Benoit Blanchon in 2015
# MIT License

cmake_minimum_required(VERSION 2.8)

project(BuckOperator)

if(CMAKE_CXX_COMPILER_ID MATCHES "(Clang|GNU)")
	add_compile_options(
		-std=c++11
		-Wall
		-Wextra
		-pedantic
		-Wno-dollar-in-identifier-extension
	)
endif()

if(MSVC)
	add_compile_options(
		/W4
	)
endif()

add_executable(example 
	buck.hpp
	example.cpp
)
