cmake_minimum_required(VERSION 3.6)
project(Octave)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pagedArray.h sortAlgorithms.h binaryConverter.h)
add_executable(Octave ${SOURCE_FILES})