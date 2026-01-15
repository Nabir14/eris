#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include<vector>

namespace SceneManager {
    class Scene {
        public:
        virtual void OnLoad();
        virtual void OnUpdate();
        virtual void OnDraw();
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