#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SDL3/SDL.h>
#include <map>
#include <string>

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

namespace InputManager {
    class Window {
        public:
            inline static const std::map<std::string, int> WindowEvent {
                {"CLOSE", SDL_EVENT_WINDOW_CLOSE_REQUESTED },
            };
        
        static int checkEvent(lua_State* L);
    };

    class InputManager {
        public:
            static SDL_Event Event;
    };
} 

#endif