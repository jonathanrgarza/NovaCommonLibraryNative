cmake_minimum_required(VERSION 3.22)

# Create the unit test project
# set the project name and version
set(PROJ_NAME NclUnitTests)
project(${PROJ_NAME} VERSION 0.1)

# Declare Sources and Headers
SET(SOURCES
        StringUtilsTests.cpp
        )

add_subdirectory(Libs/Catch2)
# These tests can use the Catch2-provided main
add_executable(${PROJ_NAME} ${SOURCES})
# Link the executable with the NCL static library
target_link_libraries(${PROJ_NAME} PRIVATE Catch2::Catch2WithMain NovaCommonLibraryNative)
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/../NovaCommonLibraryNative/include")

include(CTest)
include(Catch)
catch_discover_tests(${PROJ_NAME})