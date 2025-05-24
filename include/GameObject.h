//
// Created by nathan on 5/24/25.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <cstdint>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>


class GameObject {
    public:
        uint32_t width;
        uint32_t height;
        SDL_Texture* texture;

        GameObject(uint32_t width, uint32_t height, char* texturePath, SDL_Renderer* renderer);
        ~GameObject();
};



#endif //GAMEOBJECT_H
