#include <stdexcept>
#include "globalBinds.h"

namespace nsk {
    GlobalBinds::GlobalBinds(const std::string& path) {
        this->loadBinds(path);
    }

    GlobalBinds::~GlobalBinds() {}
    
    std::string GlobalBinds::getBind(char bind) {
        auto it = this->binds.find(bind);

        if (it == this->binds.end()) {
            throw std::runtime_error("Bind bind not found: " + std::string(1, bind));
        }

        return it->second;
    }

    // Global binds, can't be modded yet
    void GlobalBinds::setBind(char bind, std::string name) {
        this->binds[bind] = name;
    }

    void GlobalBinds::delBind(char bind) {
        this->binds.erase(bind);
    }

    void GlobalBinds::loadBinds(const std::string& path) {
        
    }
}