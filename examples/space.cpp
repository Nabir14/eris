#include <stdio.h>
#include <eris.hpp>
#include <core/scene_manager.hpp>
#include "scenes/world.hpp"

enum GameScenes {
    WORLD_SCENE = 0,
};

int main() {
    Eris::Engine::Start("Space", 640, 480);

    World::World worldScene;
    SceneManager::SceneManager::registerScene(&worldScene);

    SceneManager::SceneManager::processDefault(WORLD_SCENE);

    return 0;
}