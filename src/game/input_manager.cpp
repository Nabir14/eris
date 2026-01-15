#include "input_manager.hpp"

SDL_Event InputManager::InputManager::Event;

namespace InputManager {
    bool Window::CheckEvent(Events e) {
        SDL_PollEvent(&InputManager::Event);
        return (InputManager::Event.type == e);
    }
}