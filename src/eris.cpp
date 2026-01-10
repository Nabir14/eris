#include "eris.hpp"
#include "core/scene.hpp"
#include <iostream>

namespace Eris {
    Engine::Engine(const char* title, uint width, uint height) : title(title), width(width), height(height) {
        this->window = SDL_CreateWindow(this->title, this->width, this->height, 0);
        this->renderer =  SDL_CreateRenderer(this->window, NULL);

        SDL_Event e;
        bool run = true;
    }
}