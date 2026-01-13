#include "input_manager.hpp"

SDL_Event InputManager::InputManager::Event;

int InputManager::Window::checkEvent(lua_State* L) {
    const char* event_name = luaL_checkstring(L, 1);
    SDL_PollEvent(&InputManager::Event);

    if (InputManager::Event.type == Window::WindowEvent.at(event_name)) {
        lua_pushboolean(L, 1);
    } else {
        lua_pushboolean(L, 0);
    }

    return 1;
}