#ifndef TOOLS_INTERFACE_H
#define TOOLS_INTERFACE_H

#include <string>
#include <unordered_map>
#include "nsketch/tools.h"

namespace skt {
    class Interface {
    private:
        // map of tools
        std::unordered_map<std::string, Tool> tools;

    public:
        // Constructor
        Interface();
    
        // map control interface
        void setTool(std::string name, Tool tool);
        void getTool(std::string name);
        void delTool(std::string name);
    };
}

#endif