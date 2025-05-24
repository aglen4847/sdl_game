//
// Created by nathan on 5/22/25.
//

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

#endif //GAME_WINDOW_H

//Class to control the game screen
struct GameScreen {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* background = nullptr;
    SDL_FRect backgroundRect;

    explicit GameScreen(const char* title, const int width, const int height);
    ~GameScreen();

    SDL_Window* getWindow() const {return window;}
    SDL_Texture* setBackground(const char* imgPath);
    bool drawScreen();
};