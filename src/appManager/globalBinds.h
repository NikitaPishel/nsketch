#ifndef GLOBAL_BINDS_H
#define GLOBAL_BINDS_H

#include <string>
#include <unordered_map>

namespace nsk {
    class GlobalBinds {
    private:
        std::unordered_map<char, std::string> binds;

    public:
        GlobalBinds(const std::string& path = "./data/conf/keysGlobal.json");
        ~GlobalBinds();

        std::string getBind(char bind);
        void setBind(char bind, std::string name);
        void delBind(char bind);

        void loadBinds(const std::string& path);
    };
}

#endif