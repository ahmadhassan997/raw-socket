# add static libraries
add_library(programstate STATIC
    ProgramState.cpp
)

# add tree to the search path for include files
target_include_directories(programstate PUBLIC
    ${PROJECT_SOURCE_DIR}/src/log
    ${PROJECT_SOURCE_DIR}/include
)

# link the librares with executable
target_link_libraries(programstate PUBLIC
    log
)