#include <iostream>
#include <oneapi/tbb/profiling.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "../include/GameScreen.h"

int main() {
    bool quit = false;
    constexpr int SCREEN_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 600;


    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "SDL Init succeeded" << std::endl;


    //Create the game window and renderer
    GameScreen mainScreen = GameScreen("Game", SCREEN_WIDTH, SCREEN_HEIGHT);
    mainScreen.setBackground("../assets/textures/grass.png");
    std::cout << "Screen created" << std::endl;


    //Create delta time (time elapsed since last frame), useful for calculations
    float delta = 0;
    Uint64 currTime = SDL_GetPerformanceCounter();
    Uint64 prevTime = 0;

    //Base game running condition
    SDL_Event *event = new SDL_Event();
    while (!quit) {

        //Calculate time elapsed since last frame
        prevTime = currTime;
        currTime = SDL_GetPerformanceCounter();
        delta = static_cast<double>((currTime - prevTime) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

        SDL_PollEvent(event); //Get current frame's event

        if (!mainScreen.drawScreen()) { //Render the screen contents
            quit = true;
        }

        //Stop the loop and close the game when quit is called
        if (event->type == SDL_EVENT_QUIT) {
            quit = true;
        }
    }

    delete event;
    std::cout << "Quitting" << std::endl;
    SDL_Quit();
    return 0;
}
