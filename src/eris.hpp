#ifndef ERIS_HPP
#define ERIS_HPP

#include <string>
#include <vector>
#include <any>
#include <SDL3/SDL.h>

namespace SceneManager {
    class Scene;
}

namespace Eris {
    class Engine {
        public:
            const char* title;
            uint width;
            uint height;
            std::vector<SceneManager::Scene*> scenes;
            SDL_Window* window;
            SDL_Renderer* renderer;

        Engine(const char* title, unsigned int width, unsigned int height);
    };
}

#endif