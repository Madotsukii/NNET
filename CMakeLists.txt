# Minimum required CMake version
cmake_minimum_required(VERSION 2.6)

# Project name
project(NNET)

# The version number
set(NNET_VERSION_MAJOR 0)
set(NNET_VERSION_MINOR 1)

# Compiler instructions
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set source files
set(Sources
	src/core/core.cpp
	src/core/io.cpp
	src/core/log.cpp
)

# Option to build unittest version
option(BUILD_TEST "Build test version" OFF)

# Configure a header file to pass some of the CMake settings to the source code
configure_file(
	"${PROJECT_SOURCE_DIR}/src/config.hpp.in"
	"${PROJECT_BINARY_DIR}/config.hpp"
)

# Add the binary tree to the search path for include files so that we will find
# config.h
include_directories("${PROJECT_BINARY_DIR}")


# Optionally build unittests and add the install targets
if (BUILD_TEST)
	enable_testing()
	
	add_executable(NNET_connect src/unittest/connect.cpp ${Sources})
	add_test(NNET_connect NNET_connect)
	
	add_executable(NNET_render src/unittest/render.cpp ${Sources})
	add_test(NNET_render NNET_render)
	
	install(TARGETS NNET_connect NNET_render DESTINATION bin)
else ()
	add_executable(NNET src/main.cpp ${Sources})
	
	install(TARGETS NNET DESTINATION bin)
endif (BUILD_TEST)

install(FILES "${PROJECT_BINARY_DIR}/config.hpp" DESTINATION include)
