cmake_minimum_required(VERSION 3.11)
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
include_directories ("${PROJECT_SOURCE_DIR}/solver")
add_subdirectory(solver)

add_executable(gravity main.cpp)

target_link_libraries(gravity solver)

install(TARGETS gravity DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/gravityConfig.h" DESTINATION include)

target_compile_features(gravity PUBLIC cxx_std_17)