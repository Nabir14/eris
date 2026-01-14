#ifndef ERIS_HPP
#define ERIS_HPP

#include <string>
#include <vector>
#include <SDL3/SDL.h>

namespace SceneManager {
    class Scene;
}

enum ErisFlags {
    ENGINE = 1 << 0,
    SCENE = 1 << 1,
    INPUT_MANAGER = 1 << 2,
    SCENE_MANAGER = 1 << 3,
};

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
        static void exportDefault(const char flags);
        static bool running();
        static int quit(lua_State* L);
        static int Eris_Quit(lua_State* L);
    };
}

#endif