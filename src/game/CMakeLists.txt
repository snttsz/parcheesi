add_library(board board.c board.h)
target_link_libraries(board PUBLIC string_util)

add_library(gameLogic gameLogic.c gameLogic.h)
add_library(player player.c player.h)

target_link_libraries(gameLogic PUBLIC player)
target_link_libraries(gameLogic PUBLIC board)

target_include_directories(gameLogic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
