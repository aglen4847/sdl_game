cmake_minimum_required(VERSION 3.30)
project(sdl_game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 20)

add_executable(sdl_game src/main.cpp
        include/GameScreen.h
        src/GameScreen.cpp
        src/GameScreen.cpp
        include/GameScreen.h
        src/GameObject.cpp
        include/GameObject.h)

target_link_libraries(sdl_game "/usr/lib/libSDL3.so"
        "/usr/lib/libSDL3_image.so")
