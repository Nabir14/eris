#include "scene_manager.hpp"
#include "../eris.hpp"
#include "../game/input_manager.hpp"
#include <iostream>

namespace SceneManager {
    Scene::Scene(SceneManager* sceneManager, const char* path) : sceneManager(sceneManager) {
        this->sceneManager->registerScene(this);
        this->scriptServer = ScriptServer::ScriptServer();
        this->scriptServer.loadScript(path);
    }
    
    void Scene::load() {
        this->scriptServer.executeScript();
        std::vector<std::any> globals = this->scriptServer.callFunction("Load");
        this->data = globals;
    }
    
    void Scene::update() {
        if(this->data[0].type() == typeid(bool)) {
            if(std::any_cast<bool>(this->data[0])){
                InputManager::Window e;
                if(e.checkEvent(e.CLOSE)) {
                    this->quitGame();
                }
            }
        }
    }
    
    void Scene::draw() {
    }

    void Scene::quitGame() {
        this->scriptServer.close();
        this->sceneManager->stop();
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