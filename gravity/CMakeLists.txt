cmake_minimum_required(VERSION 3.0)
project(gravity)

set (gravity_VERSION_MAJOR 1)
set (gravity_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/gravityConfig.h.in"
  "${PROJECT_BINARY_DIR}/gravityConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find gravityConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(gravity main.cpp)
install(TARGETS gravity DESTINATION bin)
