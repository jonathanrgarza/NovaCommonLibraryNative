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
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")
#Specify the compiler/standard requirements
target_compile_features(${PROJ_NAME} PUBLIC cxx_std_14)

set(NovaCommonLibraryNative_CXX_STANDARD 14 CACHE STRING "NclRunner's CXX Standard") #Allow user to specify
set_property(CACHE NovaCommonLibraryNative_CXX_STANDARD PROPERTY STRINGS 14 17 20 23)

if (NOT NovaCommonLibraryNative_CXX_STANDARD EQUAL "14")
    set_target_properties(${PROJ_NAME} PROPERTIES
        CXX_STANDARD ${NovaCommonLibraryNative_CXX_STANDARD}
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS OFF)
endif()