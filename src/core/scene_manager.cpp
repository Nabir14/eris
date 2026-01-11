#include "scene_manager.hpp"
#include "../eris.hpp"
#include "input_manager.hpp"
#include <iostream>

namespace SceneManager {
    Scene::Scene(SceneManager* sceneManager, const char* path) : sceneManager(sceneManager) {
        this->sceneManager->registerScene(this);
        std::cout << path << std::endl;
    }
    
    void Scene::load() {
        bool shouldCheckEvent = true;
        this->data.push_back(shouldCheckEvent);
    }
    
    void Scene::update() {
        if(this->data[0].type() == typeid(bool)) 
        {
            if(std::any_cast<bool>(this->data[0])){
                InputManager::Window e;
                if(e.checkEvent(e.CLOSE)) {
                    this->sceneManager->stop();
                }
            }
        }
    }
    
    void Scene::draw() {
        std::cout << "draw" << std::endl;
    }

    SceneManager::SceneManager(Eris::Engine* engine) : engine(engine) {}

    void SceneManager::processDefault(Scene* scene) {
        scene->load();

        while(this->engine->running()) {
            scene->update();
            scene->draw();
        }
    }

    void SceneManager::registerScene(Scene* scene) {
        this->engine->scenes.push_back(scene);
    }

    void SceneManager::stop() {
        this->engine->quit();
    }
}