cmake_minimum_required(VERSION 3.22)

# Create the runner project
# set the project name and version
set(PROJ_NAME NclRunner)
project(${PROJ_NAME} VERSION 0.1)

# Declare Sources and Headers
SET(SOURCES 
        main.cpp
        )

#source_group("Sources" FILES ${SOURCES})

# Create the executable target
add_executable(${PROJ_NAME} "${SOURCES}")
#Specify the compiler/standard requirements

#Allow user to specify a C++ Standard Version for this particular executable
set(NclRunner_CXX_STANDARD "Default" CACHE STRING "NCL Runner's C++ Standard")
set_property(CACHE NclRunner_CXX_STANDARD PROPERTY STRINGS "Not Set" 14 17 20 23)
# Set the C++ Language Standard to be used
set(NclRunner_CXX_STANDARD_ACTUAL 17)
if (${NclRunner_CXX_STANDARD} STREQUAL "Default" AND DEFINED CMAKE_CXX_STANDARD)
  set(NclRunner_CXX_STANDARD_ACTUAL ${CMAKE_CXX_STANDARD})
  message("NCL Runner: Using CMAKE_CXX_STANDARD override")
elseif(NOT ${NclRunner_CXX_STANDARD} STREQUAL "Default")
  set(NclRunner_CXX_STANDARD_ACTUAL ${NclRunner_CXX_STANDARD})
  message("NCL Runner: Using NclRunner_CXX_STANDARD override")
else()
  message("NCL Runner: Using default C++ standard: ${NclRunner_CXX_STANDARD_ACTUAL}")
endif()
set_target_properties(${PROJ_NAME} PROPERTIES
        CXX_STANDARD ${NclRunner_CXX_STANDARD_ACTUAL}
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS OFF)
message("NCL Runner: C++ Standard Version Specified for NCL Runner: ${NclRunner_CXX_STANDARD_ACTUAL}")

# Link the executable with the NCL static library
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/../NovaCommonLibraryNative/include")
target_link_libraries(${PROJ_NAME} NovaCommonLibraryNative)

if(MSVC)
  #Enable Edit and Continue when on Windows and using MSVC compiler
  target_compile_options(${PROJ_NAME} PUBLIC "/ZI")
  target_link_options(${PROJ_NAME} PUBLIC "/INCREMENTAL")
endif()