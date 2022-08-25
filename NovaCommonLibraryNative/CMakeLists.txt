# Create the static library NCL project

# set the project name and version
set(PROJ_NAME NovaCommonLibraryNative)
project(${PROJ_NAME} VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Declare Sources and Headers

SET(HEADERS
        "include/OSConstants.h"
        "include/Library.h"
        "include/Logger.h"
        include/FileLogger.h)

SET(SOURCES
        "src/Library.cpp"
        "src/FileLogger.cpp")

#source_group("Headers" FILES ${HEADERS})
#source_group("Sources" FILES ${SOURCES})

# Create the library target
add_library(${PROJ_NAME} STATIC "${SOURCES}" "${HEADERS}")
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")