cmake_minimum_required(VERSION 3.20)

project(CPPokemon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

include(CTest)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(test)
