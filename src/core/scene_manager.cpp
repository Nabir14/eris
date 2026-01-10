#include "scene_manager.hpp"
#include "../eris.hpp"
#include "input_manager.hpp"
#include <iostream>

namespace SceneManager {
    Scene::Scene(Eris::Engine* engine, const char* path) : engine(engine) {
        this->engine->scenes.push_back(this);
        std::cout << path << std::endl;
    }
    
    void Scene::load() {
        InputManager::InputManager input = InputManager::InputManager();
        this->data.push_back(input.event);
    }
    
    void Scene::update() {
        // TODO: Abstract Later! It is almost 2 AM...
        while(SDL_PollEvent((SDL_Event)this->data[0])) {

        } 
    }
    
    void Scene::draw() {
        std::cout << "draw" << std::endl;
    }

    void SceneManager::process(Scene* scene) {
        scene->load();

        bool run = true;
        while(run) {
            scene->update();
            scene->draw();
        }
    }
}