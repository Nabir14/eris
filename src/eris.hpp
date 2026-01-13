#ifndef ERIS_HPP
#define ERIS_HPP

#include <string>
#include <vector>
#include <SDL3/SDL.h>

namespace SceneManager {
    class Scene;
}

namespace Eris {
    class Engine {
        public:
            inline static const char* title;
            inline static uint width;
            inline static uint height;
            inline static SDL_Window* window;
            inline static SDL_Renderer* renderer;
            inline static bool isRunning;
        
        public:
        static void start(const char* title, unsigned int width, unsigned int height);
        static bool running();
        static void quit();
    };
}

#endif