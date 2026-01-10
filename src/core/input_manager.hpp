#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SDL3/SDL.h>

namespace InputManager {
    class InputManager {
        public:
            SDL_Event event;
        InputManager();
    };
} 

#endif