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
        if(Types::pushAnyValue(this->LuaState, value)){
            lua_setglobal(this->LuaState, alias);
        } else {
            printf("Eris Script Server: Type Not Exposable.\n");
            return;
        }
    }

    void ScriptServer::exposeFunction(const char* alias, lua_CFunction function) {
        lua_pushcfunction(this->LuaState, function);
        lua_setglobal(this->LuaState, alias);
    }

    std::vector<std::any> ScriptServer::callFunction(const char* alias) {
        int old_stack = lua_gettop(this->LuaState);

        lua_getglobal(this->LuaState, alias);
        
        std::vector<std::any> values;
        
        if(lua_pcall(this->LuaState,0, LUA_MULTRET, 0) != LUA_OK) {
            printf("Eris Script Server: Error Calling Function '%s'.\n", alias);
            return values;
        }

        int return_count = lua_gettop(this->LuaState) - old_stack;



        for (int i = -return_count; i <= lua_gettop(this->LuaState); ++i){
            values.push_back(Types::getAnyValue(this->LuaState, i));
        }

        lua_pop(this->LuaState, return_count);

        return values;
    }

    std::vector<std::any> ScriptServer::callFunction(const char* alias, std::vector<std::any> args) {
        int old_stack = lua_gettop(this->LuaState);

        lua_getglobal(this->LuaState, alias);
        
        std::vector<std::any> values;
        
        for (int i = 0; i < args.size(); i++) {
            Types::pushAnyValue(this->LuaState, args[i]);
        }

        if(lua_pcall(this->LuaState, args.size(), LUA_MULTRET, 0) != LUA_OK) {
            printf("Eris Script Server: Error Calling Function '%s'.\n", alias);
            return values;
        }

        int return_count = lua_gettop(this->LuaState) - old_stack;

        for (int i = -return_count; i <= lua_gettop(this->LuaState); ++i){
            values.push_back(Types::getAnyValue(this->LuaState, i));
        }

        lua_pop(this->LuaState, return_count);

        return values;
    }

    std::any ScriptServer::getData(const char* alias) {
        lua_getglobal(this->LuaState, alias);
        std::any value = Types::getAnyValue(this->LuaState, lua_gettop(this->LuaState));
        return value;
    }

    void ScriptServer::close() {
        lua_close(this->LuaState);
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
        int type = lua_type(L, lua_gettop(L));
        
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
        if (value.type() == typeid(int)) {
            printf("int");
            printf("%d", std::any_cast<int>(value));
        } else if (value.type() == typeid(double)) {
            printf("%f", std::any_cast<double>(value));
        } else if (value.type() == typeid(const char*)) {
            printf("%s", std::any_cast<const char*>(value));
        } else if (value.type() == typeid(bool)) {
            const char* boolean = std::any_cast<bool>(value) ? "true" : "false";
            printf("%s", boolean);
        } else {
            printf("Eris Extras: Unknown Type.");
        }
    }
}