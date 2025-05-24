//
// Created by nathan on 5/22/25.
//

#include "../include/GameScreen.h"

GameScreen::GameScreen(const char* title, const int width, const int height) {
    backgroundRect.x = 0;
    backgroundRect.y = 0;
    backgroundRect.w = width;
    backgroundRect.h = height;

    //Create window and renderer
    window = SDL_CreateWindow(title, width, height, 0);
    renderer = SDL_CreateRenderer(window, NULL);

    //Check for any errors initializing window and renderer
    if (!window || !renderer) {
        std::cerr << "Failed to create screen: " << SDL_GetError() << std::endl;
    }

    std::cout << "Window and renderer created successfully!" << std::endl;
}

GameScreen::~GameScreen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(background);
}

SDL_Texture *GameScreen::setBackground(const char* imgPath) {
    background = IMG_LoadTexture(renderer, imgPath);
    if (!background) {
        std::cerr << "Failed to load image: " << SDL_GetError() << std::endl;
    }

    return background;
}

//Called every loop of main function
bool GameScreen::drawScreen() {

    //Clears the screen or returns an error
    if (!SDL_RenderClear(renderer)) {
        std::cerr << "Failed to clear renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    //Renders the background or returns an error
    if (!SDL_RenderTextureTiled(renderer, background, NULL, 1, NULL)) {
        std::cerr << "Failed to draw background: " << SDL_GetError() << std::endl;
        return false;
    }

    //Shows the rendered screen or returns an error
    if (!SDL_RenderPresent(renderer)) {
        std::cerr << "Failed to draw screen: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}
