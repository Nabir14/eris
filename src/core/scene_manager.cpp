#include "scene_manager.hpp"
#include "../eris.hpp"
#include "../game/input_manager.hpp"
#include <iostream>

namespace SceneManager {
    Scene::Scene() {
        SceneManager::registerScene(this);
    }

    void Scene::attachScript(const char* path) {
        ScriptServer::ScriptServer::loadScript(path);
    }

    void Scene::load() {
        ScriptServer::ScriptServer::executeScript();
        ScriptServer::ScriptServer::callFunction("Load");
    }
    
    void Scene::update() {
        ScriptServer::ScriptServer::callFunction("Update");
    }
    
    void Scene::draw() {
        ScriptServer::ScriptServer::callFunction("Draw");
    }

    void SceneManager::processDefault(Scene* scene) {
        scene->load();

        while(Eris::Engine::running()) {
            scene->update();
            scene->draw();
        }
    }

    void SceneManager::registerScene(Scene* scene) {
        SceneManager::scenes.push_back(scene);
    }
}