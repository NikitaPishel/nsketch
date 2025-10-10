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
    // forward declare app
    class UiTex;
    
    // Empty tool child for creating empty tools in an interface
    class EmptyTool : public Tool {
    public:
        EmptyTool() : Tool() {}
        void run() override {}
         std::unique_ptr<Tool> clone() const override;
    };

    class Interface {
    private:
        // map of tools
        std::unordered_map<char, std::unique_ptr<Tool>> tools;


        // pointers to the environment
        Sketch* sPtr;
        Cursor* cPtr;
        Palette* pPtr;

        // pointer to app
        UiTex* texPtr;

    public:
        // Constructor
        Interface();

        // sketch and cursor linking methods
        void linkSketch(Sketch& sketch);
        void linkCursor(Cursor& cursor);
        void linkPalette(Palette& palette);
        void linkUiTex(UiTex& uiTex);
        
        // sketch and cursor getter methods
        Sketch& getSketch() const;
        Cursor& getCursor() const;
        Palette& getPalette() const;

        // map control interface
        Tool& getTool(const char& bind);
        Tool* getToolPtr(const char& bind);
        void addTool(const char& bind, Tool* tool);
        void addTool(const char& bind, std::unique_ptr<Tool> tool);
        void delTool(const char& bind);
        void addToolFromStore(const char& bind, std::string name);

        void runTool(const char& bind);

        // Automatically detects keypresses and runs tools on press
        void autoRunTool();
    };
}

#endif