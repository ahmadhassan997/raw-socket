# add Boost libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS})

# add static libraries
add_library(parser SHARED
    parser/Parser.cpp
)

# add the executable
add_executable(${PROJECT_NAME} rawsocket/main.cpp)

# add the binary tree to the search path for include files
# so that we will find VersionConfig.h
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(parser PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

# link the librares with executable
target_link_libraries(${PROJECT_NAME} PUBLIC
    parser
    Boost::program_options
)