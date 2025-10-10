#ifndef TOOLS_MAIN_H
#define TOOLS_MAIN_H

#include <memory>
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"
#include "nsketch/sketch/palette.h"
#include "nsketch/uiTex.h"

namespace nsk {
    class Interface;

    class Tool {
    private:
        Interface* iPtr;
        UiTex* texPtr;

    protected:
        Sketch& getSketch();
        Cursor& getCursor();
        Palette& getPalette();
        UiTex& getUiTex();
        
    public:
        explicit Tool();
        virtual ~Tool() = default;
        
        // virtual methods
        virtual void run() = 0; 
        virtual std::unique_ptr<Tool> clone() const = 0; 

        void setInterface(Interface* iPtr);
        void setUiTex(UiTex* texPtr);
    };
}

#endif