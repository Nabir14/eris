#include <stdio.h>
#include "../src/eris.hpp"
#include "../src/core/scene_manager.hpp"
#include "../src/game/input_manager.hpp"

enum GameScenes {
    WORLD_SCENE = 0,
};

class World : public SceneManager::Scene {
    public:
        const char* loadStr = "Hello From OnLoad()";
        const char* updateStr = "Hello From OnUpdate()";
        const char* drawStr = "Hello From OnDraw()";
    
    void OnLoad() override {
        printf("%s\n", loadStr);
    }

    void OnUpdate() override {
        printf("%s\n", updateStr);
        if (InputManager::Window::CheckEvent(InputManager::Window::CLOSE)) {
            Eris::Engine::Quit();
        }

    }

    void OnDraw() override {
        printf("%s\n", drawStr);
    }
};

int main() {
    Eris::Engine::Start("Space", 640, 480);

    World worldScene;
    SceneManager::SceneManager::registerScene(&worldScene);

    SceneManager::SceneManager::processDefault(WORLD_SCENE);

    return 0;
}