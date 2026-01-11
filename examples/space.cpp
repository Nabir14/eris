#include "../src/eris.hpp"
#include "../src/core/scene_manager.hpp"
#include "../src/core/script_server.hpp"

int main() {
    /*
    Eris::Engine e = Eris::Engine("Space Game", 640, 480);
    SceneManager::SceneManager sm = SceneManager::SceneManager(&e);

    SceneManager::Scene s1 = SceneManager::Scene(&sm, "./scenes/s1.lua");
    SceneManager::Scene s2 = SceneManager::Scene(&sm, "./scenes/s2.lua");

    sm.processDefault(&s1);
    */

    ScriptServer::ScriptServer server = ScriptServer::ScriptServer();
    server.loadScript("./tests/script.lua");
    server.exposeData("cintlol", 67);
    server.executeScript();
    server.close();

    return 0;
}