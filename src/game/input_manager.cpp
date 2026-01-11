#include "input_manager.hpp"

SDL_Event InputManager::InputManager::Event;

bool InputManager::Window::checkEvent(WindowEvent event) {
    SDL_PollEvent(&InputManager::Event);

    if (InputManager::Event.type == event) {
        return true;
    } else {
        return false;
    }
}