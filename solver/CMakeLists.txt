cmake_minimum_required(VERSION 3.11)
project(solver)

# add the binary tree to the search path for include files
# so that we will find gravityConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_library(solver SHARED
			euler.cpp)

# add the binary tree to the search path for include files
# so that we will find gravityConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/headers")

target_link_libraries (solver)

install (TARGETS solver DESTINATION bin)
install (FILES solver.h DESTINATION include)

target_compile_features(solver PUBLIC cxx_std_17)