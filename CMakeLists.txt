cmake_minimum_required(VERSION 3.0)

project(Parcheesi)

# Set the path to the header files
add_subdirectory(src)
add_subdirectory(utils)

# Add the C source files
add_executable(Parcheesi ./Parcheesi.c)
target_link_libraries(Parcheesi LINK_PUBLIC game)