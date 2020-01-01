cmake_minimum_required(VERSION 3.15)
project(E3)

set(CMAKE_CXX_STANDARD 20)

add_executable(E3 main.cpp Graph.cpp Graph.h GeneticAlgorithm.cpp GeneticAlgorithm.h)