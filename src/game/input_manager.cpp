#include "input_manager.hpp"

namespace InputManager {
    SDL_Event InputManager::Event;

    void InputManager::Process() {
        SDL_PollEvent(&InputManager::Event);
    }

    bool Window::CheckEvent(Events e) {
        return (InputManager::Event.type == e);
    }
}