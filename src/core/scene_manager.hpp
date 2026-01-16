#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include<vector>
#include "../utils/color.hpp"

namespace SceneManager {
    class Scene {
        public:
            Color::RGBA defaultClearColor = Color::RGBA(0.0f, 0.0f, 0.0f, 1.0f);
        virtual void OnLoad() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnRender() = 0;
        virtual ~Scene();
    };

    class SceneManager {
        public:
            static std::vector<Scene*> scenes;
        static void registerScene(Scene* scene);
        static void processDefault(int index);
    };
}

#endif