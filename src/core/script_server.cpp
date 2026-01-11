#include "script_server.hpp"

namespace ScriptServer {
    ScriptServer::ScriptServer() {
        this->LuaState = luaL_newstate();
        luaL_openlibs(this->LuaState);
    }
    
    void ScriptServer::loadScript(const char* path) {
        this->scriptPath = path;
    }

    void ScriptServer::executeScript() {
        if (luaL_dofile(this->LuaState, this->scriptPath) == LUA_OK) {
            lua_pop(this->LuaState, lua_gettop(this->LuaState));
        } else {
            printf("Eris Script Server: Error Running Script %s.\n", this->scriptPath);
        }
    }

    void ScriptServer::exposeData(const char* alias, std::any value) {
        if (value.type() == typeid(int)) {
            lua_pushinteger(this->LuaState, std::any_cast<int>(value));
        } else if (value.type() == typeid(double)) {
            lua_pushnumber(this->LuaState, std::any_cast<lua_Number>(value));
        } else if (value.type() == typeid(const char*)) {
            lua_pushstring(this->LuaState, std::any_cast<const char*>(value));
        } else if (value.type() == typeid(bool)) {
            lua_pushboolean(this->LuaState, std::any_cast<bool>(value));
        } else {
            printf("Eris Script Server: Type Not Exposable.\n");
            return;
        }

        lua_setglobal(this->LuaState, alias);
    }

    void ScriptServer::exposeFunction(const char* alias, lua_CFunction function) {
        lua_pushcfunction(this->LuaState, function);
        lua_setglobal(this->LuaState, alias);
    }

    void ScriptServer::close() {
        lua_close(this->LuaState);
    }
}