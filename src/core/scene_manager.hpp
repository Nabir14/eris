#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include<vector>

namespace SceneManager {
    class Scene {
        public:
        virtual void OnLoad() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDraw() = 0;
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