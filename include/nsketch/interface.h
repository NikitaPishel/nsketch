#ifndef TOOLS_INTERFACE_H
#define TOOLS_INTERFACE_H

#include <string>
#include <unordered_map>
#include <memory>
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"
#include "nsketch/tools.h"

namespace nsk {
    class Interface {
    private:
        // map of tools
        std::unordered_map<std::string, std::unique_ptr<Tool>> tools;


        // pointers to the environment
        Sketch* sPtr;
        Cursor* cPtr;

    public:
        // Constructor
        Interface();

        // sketch and cursor linking methods
        void linkSketch(Sketch& sketch);
        void linkCursor(Cursor& cursor);
        
        // sketch and cursor getter methods
        Sketch& getSketch() const;
        Cursor& getCursor() const;

        // map control interface
        void setTool(std::string name, Tool* tool);
        void getTool(std::string name);
        void delTool(std::string name);
    };
}

#endif