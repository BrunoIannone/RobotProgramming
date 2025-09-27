cmake_minimum_required(VERSION 2.8.3)
project(mini_core)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

find_package(Eigen3 REQUIRED) # TODO invokes the routines to find a package called Eigen3

# add project source code
add_subdirectory(src)

# TODO do the same for executables 
add_subdirectory(executables)

#add_subdirectory serve nel CMakeLists più esterno per indicare le cartelle dove andare a cercare gli altri CMakeLists per il progetto.