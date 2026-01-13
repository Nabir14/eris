#include "eris.hpp"
#include "core/scene_manager.hpp"
#include "core/script_server.hpp"

namespace Eris {
    void Engine::start(const char* windowTitle, uint windowWidth, uint windowHeight) {
        title = windowTitle;
        width = windowWidth;
        height = windowHeight;
        window = SDL_CreateWindow(title, width, height, 0);
        renderer =  SDL_CreateRenderer(window, NULL);
        isRunning = true;
    }

    bool Engine::running() {
        if (isRunning) {
            return true;
        } else {
            return false;
        }
    }

    void Engine::quit() {
        ScriptServer::ScriptServer::close();
        isRunning = false;
    }
}