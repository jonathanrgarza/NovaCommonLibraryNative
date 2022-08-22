cmake_minimum_required(VERSION 3.22)
project(NovaCommonLibraryNative)

set(CMAKE_CXX_STANDARD 20)

# Create the static library NCL project
set(NCL_Lib NovaCommonLibraryNative)
add_library(${NCL_Lib} STATIC NovaCommonLibraryNative/src/Library.cpp NovaCommonLibraryNative/src/Logger.cpp)
target_include_directories(${NCL_Lib} PRIVATE NovaCommonLibraryNative/include)

# Create the runner project
set(APP_EXE NclRunner)
# Create the executable target
add_executable(${APP_EXE} NclRunner/main.cpp)
# Link the executable with the NCL static library
target_include_directories(${APP_EXE} PRIVATE NovaCommonLibraryNative/include)
target_link_libraries(${APP_EXE} NovaCommonLibraryNative)

if(MSVC)
  #Enable Edit and Continue when on Windows and using MSVC compiler
  target_compile_options(${APP_EXE} PUBLIC "/ZI")
  target_link_options(${APP_EXE} PUBLIC "/INCREMENTAL")
endif()