#include "input_manager.hpp"
#include "../core/script_server.hpp"

SDL_Event InputManager::InputManager::Event;

namespace InputManager {
    void InputManager::attachScript(const char* path) {
        ScriptServer::ScriptServer::loadScript(path);
        InputManager::exportDefault();
    }

    int Window::checkEvent(lua_State* L) {
        const char* event_name = luaL_checkstring(L, 1);
        SDL_PollEvent(&InputManager::Event);

        if (InputManager::Event.type == Window::WindowEvent.at(event_name)) {
            lua_pushboolean(L, 1);
        } else {
            lua_pushboolean(L, 0);
        }

        return 1;
    }
}