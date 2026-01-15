#include "scene_manager.hpp"
#include "../eris.hpp"

namespace SceneManager {
    Scene::~Scene() {}

    std::vector<Scene*> SceneManager::scenes;
    
    void SceneManager::registerScene(Scene* scene) {
        SceneManager::scenes.push_back(scene);
    }

    void SceneManager::processDefault(int index) {
        if (index < SceneManager::scenes.size()) {
            Scene* scene;
            scene = SceneManager::scenes.at(index);

            scene->OnLoad();

            while(Eris::Engine::isRunning) {
                scene->OnUpdate();
                scene->OnDraw();
            }
        }
    }
}