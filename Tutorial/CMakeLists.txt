cmake_minimum_required(VERSION 3.6)
project(Tutorial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp intVar.cpp boolCharVar.cpp)
set(SOURCE_FILES main.cpp intVar.cpp boolCharVar.cpp floatDoubleVarConst.cpp Operadores.cpp switch.cpp forArrays.cpp define.cpp estructuras.cpp namespace.cpp punteros.cpp clases.cpp)
add_executable(Tutorial ${SOURCE_FILES})