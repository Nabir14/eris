#include <glad/glad.h>
#include "eris.hpp"


namespace Eris {
    bool Engine::isRunning;
    SDL_Window* Engine::window;
    SDL_Renderer* Engine::renderer;
    SDL_GLContext Engine::glContext;

    void Engine::Start(const char* title, int width, int height) {
        Engine::isRunning = true;

        SDL_Init(SDL_INIT_VIDEO);
        
        Engine::window = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL);
        Engine::renderer = SDL_CreateRenderer(Engine::window, NULL);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        Engine::glContext = SDL_GL_CreateContext(Engine::window);
        SDL_GL_MakeCurrent(Engine::window, Engine::glContext);

        gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

        glViewport(0, 0, width, height);
    }

    void Engine::Quit() {
        SDL_GL_DestroyContext(Engine::glContext);
        SDL_DestroyWindow(Engine::window);
        SDL_DestroyRenderer(Engine::renderer);
        SDL_Quit();
        Engine::isRunning = false;
    }
}