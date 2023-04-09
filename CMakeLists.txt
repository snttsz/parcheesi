cmake_minimum_required(VERSION 3.0)

project(board_game)

# Set the path to the header files
add_subdirectory(src)
add_subdirectory(utils)

# Add the C source files
add_executable(board_game ./main.c)
target_link_libraries(board_game LINK_PUBLIC gameConstructor)