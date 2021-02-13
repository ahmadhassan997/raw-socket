cmake_minimum_required(VERSION 3.10)
project("rawsocket" VERSION 1.0.0
                    DESCRIPTION "Transport protocol implementations using linux raw socket")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(VersionConfig.h.in VersionConfig.h)

# add subdirectries
add_subdirectory(src)
