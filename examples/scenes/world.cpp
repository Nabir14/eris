#include <stdio.h>
#include <game/input_manager.hpp>
#include <eris.hpp>
#include "world.hpp"


namespace World {
    World::World() {
        this->defaultClearColor = Color::RGBA(0.025f, 0.05f, 0.1f, 1.0f);
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

    void World::OnRender() {

    }
}