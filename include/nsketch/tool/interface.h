#ifndef TOOLS_INTERFACE_H
#define TOOLS_INTERFACE_H

#include <string>
#include <unordered_map>
#include <memory>
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"
#include "nsketch/sketch/palette.h"
#include "nsketch/tool/tool.h"

namespace nsk {
    // Empty tool child for creating empty tools in an interface
    class EmptyTool : public Tool {
    public:
        EmptyTool() : Tool() {}
        void apply() {}
         std::unique_ptr<Tool> clone() const override;
    };

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
        Tool& getTool(const std::string& name);
        void addTool(const std::string& name, Tool* tool);
        void addTool(const std::string& name, std::unique_ptr<Tool> tool);
        void delTool(const std::string& name);
        void addToolFromStore(const std::string& name);

        void useTool(const std::string& name);
    };
}

#endif