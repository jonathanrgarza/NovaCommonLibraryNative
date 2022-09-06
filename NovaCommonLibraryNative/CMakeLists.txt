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

#Allow user to specify a C++ Standard Version for this particular library
set(NovaCommonLibraryNative_CXX_STANDARD "Default" CACHE STRING "Nova Common Library's C++ Standard")
set_property(CACHE NovaCommonLibraryNative_CXX_STANDARD PROPERTY STRINGS "Not Set" 14 17 20 23)

set(NovaCommonLibraryNative_CXX_STANDARD_ACTUAL 14)
if (${NovaCommonLibraryNative_CXX_STANDARD} STREQUAL "Default" AND DEFINED CMAKE_CXX_STANDARD)
	set(NovaCommonLibraryNative_CXX_STANDARD_ACTUAL ${CMAKE_CXX_STANDARD})
	message("Nova Common Library: Using CMAKE_CXX_STANDARD override")
elseif(NOT ${NovaCommonLibraryNative_CXX_STANDARD} STREQUAL "Default")
	set(NovaCommonLibraryNative_CXX_STANDARD_ACTUAL ${NovaCommonLibraryNative_CXX_STANDARD})
	message("Nova Common Library: Using NovaCommonLibraryNative_CXX_STANDARD_ACTUAL override")
else()
	message("Nova Common Library: Using default C++ standard: ${NovaCommonLibraryNative_CXX_STANDARD_ACTUAL}")
endif()
set_target_properties(${PROJ_NAME} PROPERTIES
		CXX_STANDARD ${NovaCommonLibraryNative_CXX_STANDARD_ACTUAL}
		CXX_STANDARD_REQUIRED TRUE
		CXX_EXTENSIONS OFF)
message("Nova Common Library: C++ Standard Version Specified for NCL: ${NovaCommonLibraryNative_CXX_STANDARD_ACTUAL}")