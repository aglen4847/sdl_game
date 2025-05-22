cmake_minimum_required(VERSION 3.30)
project(sdl_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(sdl_game src/main.cpp)

target_link_libraries(sdl_game "/usr/lib/libSDL3.so")
