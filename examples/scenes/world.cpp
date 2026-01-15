#include "world.hpp"
#include <stdio.h>
#include "../../src/game/input_manager.hpp"
#include "../../src/eris.hpp"

namespace World {
    World::World() {
        this->text = "[SpaceLog: World Scene Loaded.]";
    }

    void World::OnLoad() {
        printf("%s\n", this->text);
    }

    void World::OnUpdate() {
        if (InputManager::Window::CheckEvent(InputManager::Window::CLOSE)) {
            Eris::Engine::Quit();
        }
    }

    void World::OnDraw() {

    }
}