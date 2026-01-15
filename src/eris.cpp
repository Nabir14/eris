#include "eris.hpp"

namespace Eris {
    void Engine::Start(const char* title, int width, int height) {
        Engine::isRunning = true;
        Engine::window = SDL_CreateWindow(title, width, height, 0);
        Engine::renderer = SDL_CreateRenderer(Engine::window, NULL);
    }

    void Engine::Quit() {
        SDL_DestroyWindow(Engine::window);
        SDL_DestroyRenderer(Engine::renderer);
        SDL_Quit();
        Engine::isRunning = false;
    }
}