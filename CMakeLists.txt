cmake_minimum_required(VERSION 3.10)
project("rawsocket" VERSION 1.0.0
                    DESCRIPTION "Transport protocol implementations using linux raw socket")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add Boost libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(VersionConfig.h.in VersionConfig.h)

# add subdirectries
add_subdirectory(src)
