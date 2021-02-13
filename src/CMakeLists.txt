# add static libraries
add_library(parser STATIC
    parser/ArgumentParser.cpp
)

# add the executable
add_executable(${PROJECT_NAME} rawsocket/main.cpp)

# add the binary tree to the search path for include files
# so that we will find VersionConfig.h
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(parser PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# link the librares with executable
target_link_libraries(${PROJECT_NAME} PRIVATE
    parser
)