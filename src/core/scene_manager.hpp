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
    using GlobalData = std::vector<std::any>;

    class SceneManager;

    class Scene {
        private:
            GlobalData data;
            SceneManager* sceneManager;
            ScriptServer::ScriptServer scriptServer;

        public:
        Scene(SceneManager* sceneManager, const char* path);
        void load();
        void update();
        void draw();
        void quitGame();
    };

    class SceneManager {
        private:
            Eris::Engine* engine;

        public:
        SceneManager(Eris::Engine* engine);
        void registerScene(Scene* scene);
        void processDefault(Scene* scene);
        void stop();
    };
} 

#endif