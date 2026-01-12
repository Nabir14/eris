#ifndef SCRIPT_SERVER_HPP
#define SCRIPT_SERVER_HPP

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#include <any>
#include <functional>
#include <cstdarg>

namespace ScriptServer {
    class Types {
        public:
        static bool pushAnyValue(lua_State* L, std::any value);
        static std::any getAnyValue(lua_State* L, int stack_index);
    };

    class ScriptServer {
        public:
            const char* scriptPath;

        ScriptServer();
        void loadScript(const char* path);
        void executeScript();
        void exposeData(const char* alias, std::any value);
        void exposeFunction(const char* name, lua_CFunction function);
        std::vector<std::any> callFunction(const char* alias);
        std::vector<std::any> callFunction(const char* alias, std::vector<std::any> args);
        std::any getData(const char* alias);
        void close();

        private:
            lua_State* LuaState;
    };
}

#endif