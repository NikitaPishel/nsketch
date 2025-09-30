#ifndef TOOLS_INTERFACE_H
#define TOOLS_INTERFACE_H

#include <string>
#include <unordered_map>
#include <memory>
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"
#include "nsketch/tool.h"
#include "nsketch/palette.h"

namespace nsk {
    class Interface {
    private:
        // map of tools
        std::unordered_map<std::string, std::unique_ptr<Tool>> tools;


        // pointers to the environment
        Sketch* sPtr;
        Cursor* cPtr;
        Palette* pPtr;

    public:
        // Constructor
        Interface();

        // sketch and cursor linking methods
        void linkSketch(Sketch& sketch);
        void linkCursor(Cursor& cursor);
        void linkPalette(Palette& palette);
        
        // sketch and cursor getter methods
        Sketch& getSketch() const;
        Cursor& getCursor() const;
        Palette& getPalette() const;

        // map control interface
        Tool& getTool(std::string name);
        void setTool(std::string name, Tool* tool);
        void setTool(std::string name, std::unique_ptr<Tool> tool);
        void delTool(std::string name);
    };
}

#endif