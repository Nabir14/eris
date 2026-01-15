#ifndef ERIS_HPP
#define ERIS_HPP

#include <SDL3/SDL.h>

namespace Eris {
    class Engine {
        private:
            static SDL_Window* window;
            static SDL_Renderer* renderer;
        public:
            static bool isRunning;
        static void Start(const char* title, int width, int height);
        static void Quit();
    };
}

#endif