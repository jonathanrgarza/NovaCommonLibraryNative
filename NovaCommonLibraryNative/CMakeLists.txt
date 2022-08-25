# Create the static library NCL project
set(NCL_Lib NovaCommonLibraryNative)
add_library(${NCL_Lib} STATIC src/Library.cpp src/Logger.cpp include/OSConstants.h)
target_include_directories(${NCL_Lib} PRIVATE include)