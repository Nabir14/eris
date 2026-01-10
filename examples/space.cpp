#include "../src/eris.hpp"
#include "../src/core/scene_manager.hpp"

int main() {
    Eris::Engine e = Eris::Engine("Space Game", 640, 480);
    SceneManager::Scene s1 = SceneManager::Scene(&e, "./scenes/s1.lua");
    SceneManager::Scene s2 = SceneManager::Scene(&e, "./scenes/s2.lua");
    SceneManager::SceneManager sm;

    sm.process(&s1);
    return 0;
}