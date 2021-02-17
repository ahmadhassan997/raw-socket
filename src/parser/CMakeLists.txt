# add static libraries
add_library(parser SHARED
    Parser.cpp
)

# add the binary tree to the search path for include files
target_include_directories(parser PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
)