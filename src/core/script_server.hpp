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
    class ScriptServer {
        public:
            const char* scriptPath;

        ScriptServer();
        void loadScript(const char* path);
        void executeScript();
        void exposeData(const char* alias, std::any value);
        void exposeFunction(const char* name, lua_CFunction function);
        std::any callFunction(const char* alias);
        std::any ScriptServer::callFunction(const char* alias, int arg_count, ...);
        std::any getData(const char* alias);
        void close();

        private:
            lua_State* LuaState;
    };
}

#endif