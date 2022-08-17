# --------------------------------------------------
# CMAKE VERSION
# --------------------------------------------------
cmake_minimum_required(VERSION 3.12)

# --------------------------------------------------
# PROJECT NAME AND VERSION
# --------------------------------------------------
project(Solution VERSION 1.0)

# --------------------------------------------------
# GENERATE COMPILATION DATABASE (FOR YCM)
# --------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------------
# BUILD SHARED LIBRARIES
# --------------------------------------------------
#option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# --------------------------------------------------
# CONFIGURATION HEADER
# --------------------------------------------------
#Having 2 options to link the libraries: 
#1. Cotains the CMakeLists.txt inside the subdirectory of that library 
	#Sub: add_library(name path/source_files)
	#target_include_directories(name [PRO] path/)
	#Top: add_subdirectory(path)
#2. Declare that library inside the top CMakeLists.txt
add_subdirectory(inlib/interp)
#Without the source files {.h .hpp .h.in}
#Outsource libraries which built outside the current project regularly is headers only! 
#[INTERFACE] stands for header's libraries only! 
add_library(outlib INTERFACE)
target_include_directories(outlib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/outlib/")

#configure_file(outsource/Config.h.in 
#    ${CMAKE_CURRENT_SOURCE_DIR}/outsource/Config.h)
# --------------------------------------------------
# EXECUTABLE
# --------------------------------------------------
add_executable(Solution
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

#links targets together - executable targets & library_targets
target_link_libraries(Solution PUBLIC interp outlib)
# --------------------------------------------------
# SET OUTPUT DIRECTORIES
# --------------------------------------------------
set_target_properties(Solution
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")
     
# --------------------------------------------------
# COMPILER FLAGS
# --------------------------------------------------
target_compile_features(Solution PUBLIC cxx_std_11)

# add compiler warning flags just when building this project
# via the BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_flags "-Wall;-Wextra;-Wshadow;-Wshadow;-Wformat=2")
set(msvc_flags "-W3")

target_compile_options(Solution PRIVATE
   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")

 target_compile_options(Solution PRIVATE
   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")

