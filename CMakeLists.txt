cmake_minimum_required(VERSION 3.17)
project(RawSocket VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(VersionConfig.h.in VersionConfig.h)

# add the executable
add_executable(rawsocket src/main.cpp)

# add the binary tree to the search path for include files
# so that we will find VersionConfig.h
target_include_directories(rawsocket PUBLIC
        "${PROJECT_BINARY_DIR}"
        )
