cmake_minimum_required(VERSION 3.11)
project(solver)

set (solver_VERSION_MAJOR 1)
set (solver_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/solverConfig.h.in"
  "${PROJECT_BINARY_DIR}/solverConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find gravityConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_library(solver SHARED
			solver.cpp)

install (TARGETS solver DESTINATION bin)
install (FILES solver.h DESTINATION include)