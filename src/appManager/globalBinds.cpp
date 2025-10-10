#include <stdexcept>
#include "globalBinds.h"
#include "nsketch/iokey.h"

namespace nsk {
    GlobalBinds::GlobalBinds(const std::string& path) {
        this->loadBinds(path);
    }

    GlobalBinds::~GlobalBinds() {}
    
    const std::string* GlobalBinds::getBind(char bind) {
        auto it = this->binds.find(bind);

        if (it == this->binds.end()) {
            return nullptr;
        }

        return &it->second;
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

    const std::string* GlobalBinds::autoGetBind() {
            IoKey& ioKey = IoKey::getInstance();
            
            return this->getBind(ioKey.getChar());
        }
}