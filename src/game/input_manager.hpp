#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SDL3/SDL.h>

namespace InputManager {
    class InputManager {
        public:
            static SDL_Event Event;
        static void Process();
    };

    class Window {
        public:
            enum Events {
                CLOSE = SDL_EVENT_WINDOW_CLOSE_REQUESTED,
            };

        static bool CheckEvent(Events e);
    };
}

#endif