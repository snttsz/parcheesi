add_library(board board.c board.h)
add_library(game game.c game.h)

target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})