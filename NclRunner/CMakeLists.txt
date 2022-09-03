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
target_compile_features(${PROJ_NAME} PUBLIC cxx_std_14)
set_target_properties(${PROJ_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED TRUE)
# Link the executable with the NCL static library
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/../NovaCommonLibraryNative/include")
target_link_libraries(${PROJ_NAME} NovaCommonLibraryNative)

if(MSVC)
  #Enable Edit and Continue when on Windows and using MSVC compiler
  target_compile_options(${PROJ_NAME} PUBLIC "/ZI")
  target_link_options(${PROJ_NAME} PUBLIC "/INCREMENTAL")
endif()