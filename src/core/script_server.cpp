#include "script_server.hpp"

namespace ScriptServer {
    ScriptServer::ScriptServer() {
        LuaState = luaL_newstate();
        luaL_openlibs(LuaState);
    }
    
    void ScriptServer::loadScript(const char* path) {
        scriptPath = path;
    }

    void ScriptServer::executeScript() {
        if (luaL_dofile(LuaState, scriptPath) == LUA_OK) {
            lua_pop(LuaState, lua_gettop(LuaState));
        } else {
            printf("Eris Script Server: Error Running Script %s.\n", scriptPath);
        }
    }

    void ScriptServer::exposeData(const char* alias, std::any value) {
        if(Types::pushAnyValue(LuaState, value)){
            lua_setglobal(LuaState, alias);
        } else {
            printf("Eris Script Server: Type Not Exposable.\n");
            return;
        }
    }

    void ScriptServer::exposeFunction(const char* alias, lua_CFunction function) {
        lua_pushcfunction(LuaState, function);
        lua_setglobal(LuaState, alias);
    }

    std::vector<std::any> ScriptServer::callFunction(const char* alias) {
        int old_stack = lua_gettop(LuaState);

        lua_getglobal(LuaState, alias);
        
        std::vector<std::any> values;
        
        if(lua_pcall(LuaState,0, LUA_MULTRET, 0) != LUA_OK) {
            printf("Eris Script Server: Error Calling Function '%s'.\n", alias);
            return values;
        }

        int return_count = lua_gettop(LuaState) - old_stack;

        for (int i = -return_count; i <= -1; ++i){
            printf("[Printing Return Values]: ");
            std::any value = Types::getAnyValue(LuaState, i);
            Types::printVariable(value);
            values.push_back(Types::getAnyValue(LuaState, i));
        }

        lua_pop(LuaState, return_count);

        return values;
    }

    std::vector<std::any> ScriptServer::callFunction(const char* alias, std::vector<std::any> args) {
        int old_stack = lua_gettop(LuaState);

        lua_getglobal(LuaState, alias);
        
        std::vector<std::any> values;
        
        for (int i = 0; i < args.size(); i++) {
            Types::pushAnyValue(LuaState, args[i]);
        }

        if(lua_pcall(LuaState, args.size(), LUA_MULTRET, 0) != LUA_OK) {
            printf("Eris Script Server: Error Calling Function '%s'.\n", alias);
            return values;
        }

        int return_count = lua_gettop(LuaState) - old_stack;

        for (int i = -return_count; i <= -1; ++i){
            values.push_back(Types::getAnyValue(LuaState, i));
        }

        lua_pop(LuaState, return_count);

        return values;
    }

    std::any ScriptServer::getData(const char* alias) {
        lua_getglobal(LuaState, alias);
        std::any value = Types::getAnyValue(LuaState, lua_gettop(LuaState));
        return value;
    }

    void ScriptServer::close() {
        lua_close(LuaState);
    }

    bool Types::pushAnyValue(lua_State* L, std::any value) {
        if (value.type() == typeid(int)) {
            lua_pushinteger(L, std::any_cast<int>(value));
        } else if (value.type() == typeid(double)) {
            lua_pushnumber(L, std::any_cast<lua_Number>(value));
        } else if (value.type() == typeid(const char*)) {
            lua_pushstring(L, std::any_cast<const char*>(value));
        } else if (value.type() == typeid(bool)) {
            lua_pushboolean(L, std::any_cast<bool>(value));
        } else {
            return false;
        }

        return true;
    }
    
    std::any Types::getAnyValue(lua_State* L, int stack_index) {
        int type = lua_type(L, stack_index);
        
        switch (type) {
            case LUA_TSTRING:
                return std::any(lua_tostring(L, stack_index));
            case LUA_TBOOLEAN:
                return std::any((bool)lua_toboolean(L, stack_index));
            case LUA_TNUMBER:
                return std::any((double)lua_tonumber(L, stack_index));
            default:
                return std::any("");
        }
    }

    void Types::printVariable(std::any value) {
        if (value.type() == typeid(double)) {
            printf("%f\n", std::any_cast<double>(value));
        } else if (value.type() == typeid(const char*)) {
            printf("%s\n", std::any_cast<const char*>(value));
        } else if (value.type() == typeid(bool)) {
            const char* boolean = std::any_cast<bool>(value) ? "true" : "false";
            printf("%s\n", boolean);
        } else {
            printf("Eris Extras: Unknown Type.");
        }
    }
}