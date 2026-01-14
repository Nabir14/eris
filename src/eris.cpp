#include "eris.hpp"
#include "core/scene_manager.hpp"
#include "core/script_server.hpp"
#include "game/input_manager.hpp"

namespace Eris {
    void Engine::start(const char* windowTitle, uint windowWidth, uint windowHeight) {
        title = windowTitle;
        width = windowWidth;
        height = windowHeight;
        window = SDL_CreateWindow(title, width, height, 0);
        renderer =  SDL_CreateRenderer(window, NULL);
        isRunning = true;
        ScriptServer::ScriptServer::start();
    }

    void Engine::exportDefault(const char flags) {
        if (flags & ENGINE) {
            ScriptServer::ScriptServer::exposeFunction("Eris_Quit", Engine::Eris_Quit);
        }
        
        if (flags & SCENE) {

        }
        
        if (flags & INPUT_MANAGER) {
            ScriptServer::ScriptServer::exposeFunction("Eris_CheckWindowEvent", InputManager::Window::checkEvent);
        }
        
        if(flags & SCENE_MANAGER) {

        }
    }

    bool Engine::running() {
        if (isRunning) {
            return true;
        } else {
            return false;
        }
    }

    int Engine::quit(lua_State* L) {
        isRunning = false;
        ScriptServer::ScriptServer::close();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);

        return 0;
    }
}