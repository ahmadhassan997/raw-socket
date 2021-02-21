# add library
add_library(common STATIC
    Common.cpp
)

# add tree to the search path for include files
target_include_directories(common PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/log
)

# link the librares with executable
target_link_libraries(common PUBLIC
    log
)