# add library
add_library(log STATIC
    Log.cpp
)

# add tree to the search path for include files
target_include_directories(log PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)