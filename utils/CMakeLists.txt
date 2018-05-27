cmake_minimum_required(VERSION 3.11)
project(utils)

# add the binary tree to the search path for include files
# so that we will find gravityConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_library(utils SHARED
			utils.cpp)

install (TARGETS utils DESTINATION bin)
install (FILES utils.h DESTINATION include)