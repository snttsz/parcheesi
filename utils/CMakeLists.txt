add_library(string_util String_utils.c String_utils.h)

target_include_directories(string_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})