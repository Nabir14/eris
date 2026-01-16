#include <glad/glad.h>
#include "scene_manager.hpp"
#include "../eris.hpp"
#include "../game/input_manager.hpp"

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

                glClearColor(scene->defaultClearColor.r, scene->defaultClearColor.g, scene->defaultClearColor.b, scene->defaultClearColor.a);
                glClear(GL_COLOR_BUFFER_BIT);
                
                scene->OnRender();
                
                InputManager::InputManager::Process();
                SDL_GL_SwapWindow(Eris::Engine::window);
            }
        }
    }
}