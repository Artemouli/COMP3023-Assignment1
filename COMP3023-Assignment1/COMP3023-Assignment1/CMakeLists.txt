# CMakeList.txt : CMake project for COMP3023-Assignment1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (COMP3023-Assignment1 "COMP3023-Assignment1.cpp" "COMP3023-Assignment1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET COMP3023-Assignment1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
