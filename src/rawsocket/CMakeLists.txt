# add the executable
add_executable(rawsocket main.cpp)

# add the binary tree to the search path for include files
# so that we will find VersionConfig.h
target_include_directories(rawsocket PUBLIC
        "${PROJECT_BINARY_DIR}"
        )
