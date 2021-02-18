# add sub-directories
add_subdirectory(parser)
add_subdirectory(state)
add_subdirectory(log)
add_subdirectory(rules)

# add the executable
add_executable(${PROJECT_NAME} rawsocket/main.cpp)

# add the binary tree to the search path for include files
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
    ${CMAKE_CURRENT_SOURCE_DIR}/log
    ${CMAKE_CURRENT_SOURCE_DIR}/state
    ${CMAKE_CURRENT_SOURCE_DIR}/rules
)

# link the librares with executable
target_link_libraries(${PROJECT_NAME} PUBLIC
    parser
    Boost::program_options
    log
    programstate
    rules
)