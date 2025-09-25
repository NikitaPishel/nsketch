#ifndef TOOLS_INTERFACE_H
#define TOOLS_INTERFACE_H

#include <string>
#include <unordered_map>
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"
#include "nsketch/tools.h"

namespace nsk {
    class Interface {
    private:
        // map of tools
        std::unordered_map<std::string, Tool> tools;


        // pointers to the environment
        Cursor* cPtr;
        Sketch* sPtr;

    public:
        // Constructor
        Interface();

        // map control interface
        void setTool(std::string name, Tool* tool);
        void getTool(std::string name);
        void delTool(std::string name);
    };
}

#endif