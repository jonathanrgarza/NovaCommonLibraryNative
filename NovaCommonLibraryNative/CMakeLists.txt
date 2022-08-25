# Create the static library NCL project

# set the project name and version
set(PROJ_NAME NovaCommonLibraryNative)
project(${PROJ_NAME} VERSION 0.1)

# Declare Sources and Headers

SET(HEADERS
  "${PROJECT_SOURCE_DIR}/include/OSConstants.h"
  "${PROJECT_SOURCE_DIR}/include/Library.h"
  "${PROJECT_SOURCE_DIR}/include/Logger.h"
)

SET(SOURCES
  "${PROJECT_SOURCE_DIR}/src/Library.cpp"
  "${PROJECT_SOURCE_DIR}/src/Logger.cpp"
)

#source_group("Headers" FILES ${HEADERS})
#source_group("Sources" FILES ${SOURCES})

# Create the library target
add_library(${PROJ_NAME} STATIC "${SOURCES}" "${HEADERS}")
target_include_directories(${PROJ_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")