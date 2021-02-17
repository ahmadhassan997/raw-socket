# add static libraries
add_library(programstate STATIC
    ProgramState.cpp
)

# get parent dir
# get_filename_component(PARENT_DIR ../ ABSOLUTE)

# add tree to the search path for include files
target_include_directories(programstate PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${SOURCE_FILES_DIR}/log
)