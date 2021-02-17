# add static libraries
add_library(parser STATIC
    Parser.cpp
)

# add tree to the search path for include files
target_include_directories(parser PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/state
)

# link the librares with executable
target_link_libraries(parser PUBLIC
    programstate
)