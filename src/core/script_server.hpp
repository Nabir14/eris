#ifndef SCRIPT_SERVER_HPP
#define SCRIPT_SERVER_HPP

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#include <any>
#include <vector>
#include <cstdarg>

namespace ScriptServer {
    class Types {
        public:
        static bool pushAnyValue(lua_State* L, std::any value);
        static std::any getAnyValue(lua_State* L, int stack_index);
        static void printVariable(std::any value);
    };

    class ScriptServer {
        public:
            inline static const char* scriptPath;
            inline static lua_State* LuaState;
        static void start();
        static void loadScript(const char* path);
        static void executeScript();
        static void exposeData(const char* alias, std::any value);
        static void exposeFunction(const char* name, lua_CFunction function);
        static std::vector<std::any> callFunction(const char* alias);
        static std::vector<std::any> callFunction(const char* alias, std::vector<std::any> args);
        static std::any getData(const char* alias);
        static void close();
    };
}

#endif