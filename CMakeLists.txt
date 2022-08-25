cmake_minimum_required(VERSION 3.22)

# set the project name and version
project(NovaCommonLibraryNative VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# add the NCLN library
add_subdirectory(NovaCommonLibraryNative)

# add the NclRunner project
add_subdirectory(NclRunner)
