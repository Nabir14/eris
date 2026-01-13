#include "../src/eris.hpp"
#include "../src/core/scene_manager.hpp"

int add(lua_State* L) {
    lua_Integer a = luaL_checkinteger(L, 1);
    lua_Integer b = luaL_checkinteger(L, 2);
    lua_Integer s = a + b;
    lua_pushinteger(L, s);
    return 1;
}

int main() {
    printf("hey");
    Eris::Engine::start("Space", 640, 480);
    SceneManager::Scene s1 = SceneManager::Scene();
    s1.attachScript("scenes/s1.lua");
    s1.exportDefault();

    SceneManager::Scene s2 = SceneManager::Scene();

    SceneManager::SceneManager::processDefault(&s1);

    return 0;
}