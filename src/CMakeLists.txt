add_subdirectory(game)
add_subdirectory(comm)

add_library(gameConstructor gameConstructor.c gameConstructor.h)
target_link_libraries(gameConstructor PUBLIC gameLogic)

target_include_directories(gameConstructor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})