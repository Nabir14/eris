#include "../src/eris.hpp"
#include "../src/core/scene_manager.hpp"
#include "../src/core/script_server.hpp"

int add(lua_State* L) {
    lua_Integer a = luaL_checkinteger(L, 1);
    lua_Integer b = luaL_checkinteger(L, 2);
    lua_Integer s = a + b;
    lua_pushinteger(L, s);
    return 1;
}

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
    server.exposeFunction("sum", add);
    server.executeScript();
    server.callFunction("hello");
    server.close();

    return 0;
}