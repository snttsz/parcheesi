add_library(socket socket.c socket.h)

target_include_directories(socket PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})