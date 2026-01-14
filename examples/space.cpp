#include "../src/eris.hpp"
#include "../src/core/scene_manager.hpp"
#include "../src/game/input_manager.hpp"

int main() {
    Eris::Engine::start("Space", 640, 480);
    Eris::Engine::exportDefault(ENGINE | INPUT_MANAGER);

    SceneManager::Scene s1 = SceneManager::Scene();
    s1.attachScript("./scenes/s1.lua");

    SceneManager::Scene s2 = SceneManager::Scene();

    SceneManager::SceneManager::processDefault(&s1);

    return 0;
}