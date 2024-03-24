# CMakeList.txt : CMake project for Comp3023Assignment1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Comp3023Assignment1")

# Add source to this project's executable.
add_executable (Comp3023Assignment1 "Comp3023Assignment1.cpp" "Comp3023Assignment1.h" "Game.cpp" "Game.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Comp3023Assignment1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
