# add static libraries
add_library(rules STATIC
    Rules.cpp
)

# add tree to the search path for include files
target_include_directories(rules PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/log
    ${PROJECT_SOURCE_DIR}/src/common
    ${PROJECT_SOURCE_DIR}/src/state
)

# link the librares with executable
target_link_libraries(rules PUBLIC
    log
    common
    programstate
)