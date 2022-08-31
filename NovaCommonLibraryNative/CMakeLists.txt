# Create the static library NCL project

# set the project name and version
set(PROJ_NAME NovaCommonLibraryNative)
project(${PROJ_NAME} VERSION 0.1)

# Declare Sources and Headers

SET(HEADERS
        include/OSConstants.h
        include/Library.h
        include/Logger.h
        include/FileLogger.h
        include/StringUtils.h
        include/Macros.h)

SET(SOURCES
        src/Library.cpp
        src/FileLogger.cpp
        src/StringUtils.cpp)

#source_group("Headers" FILES ${HEADERS})
#source_group("Sources" FILES ${SOURCES})

# Create the library target
add_library(${PROJ_NAME} STATIC "${SOURCES}" "${HEADERS}")
#Specify the compiler/standard requirements
set_target_properties(${PROJ_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED TRUE)
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")