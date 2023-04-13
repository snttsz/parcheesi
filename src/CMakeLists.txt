add_subdirectory(game)
add_subdirectory(comm)

add_library(game game.c game.h)
target_link_libraries(game PUBLIC gameLogic)
target_link_libraries(game PUBLIC board)
target_link_libraries(game PUBLIC gameState)


target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})