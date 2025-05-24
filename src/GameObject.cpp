//
// Created by nathan on 5/24/25.
//

#include "../include/GameObject.h"


GameObject::GameObject(uint32_t width, uint32_t height, char *texturePath, SDL_Renderer* renderer) {
    this->width = width;
    this->height = height;
    this->texture = IMG_LoadTexture(renderer, texturePath);
}

GameObject::~GameObject() {
    SDL_DestroyTexture(texture);
}
