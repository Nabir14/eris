#include "eris.hpp"
#include "core/scene_manager.hpp"

namespace Eris {
    Engine::Engine(const char* title, uint width, uint height) : title(title), width(width), height(height) {
        this->window = SDL_CreateWindow(this->title, this->width, this->height, 0);
        this->renderer =  SDL_CreateRenderer(this->window, NULL);

        this->isRunning = true;
    }

    bool Engine::running() {
        if (this->isRunning) {
            return true;
        } else {
            return false;
        }
    }

    void Engine::quit() {
        this->isRunning = false;
    }
}