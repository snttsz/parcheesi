add_library(board board.c board.h)
target_link_libraries(board PUBLIC string_util)

add_library(gameLogic gameLogic.c gameLogic.h)
add_library(player player.c player.h)
add_library(gameState gameState.h gameState.c)

target_link_libraries(gameState PUBLIC string_util)
target_link_libraries(gameState PUBLIC player)

target_link_libraries(gameLogic PUBLIC gameState)

target_include_directories(gameLogic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})