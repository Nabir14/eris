#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <vector>
#include <any>
#include <SDL3/SDL.h>
#include "script_server.hpp"

namespace Eris {
    class Engine;
}

namespace SceneManager {
    class SceneManager;

    class Scene {
        public:
        Scene();
        void attachScript(const char* path);
        void exportDefault();
        void load();
        void update();
        void draw();
    };

    class SceneManager {
        public:
            inline static std::vector<Scene*> scenes;
        static void registerScene(Scene* scene);
        static void processDefault(Scene* scene);
    };
} 

int Eris_Quit(lua_State* L);

#endif