#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <vector>
#include <any>
#include <SDL3/SDL.h>

namespace Eris {
    class Engine;
}

namespace SceneManager {
    using GlobalData = std::vector<std::any>;

    class Scene {
        private:
            GlobalData data;
            Eris::Engine* engine;

        public:
        Scene(Eris::Engine* engine, const char* path);
        void load();
        void update();
        void draw();
    };

    class SceneManager {
        public:
        static void process(Scene* scene);
    };
} 

#endif