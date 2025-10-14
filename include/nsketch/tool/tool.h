#ifndef TOOLS_MAIN_H
#define TOOLS_MAIN_H

#include <memory>
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"
#include "nsketch/sketch/palette.h"
#include "nsketch/uiCanv.h"

namespace nsk {
    class Interface;

    class Tool {
    private:
        Interface* iPtr;
        UiCanv* uiPtr;

    protected:
        Sketch& getSketch();
        Cursor& getCursor();
        Palette& getPalette();
        UiCanv& getUiCanv();
        
    public:
        explicit Tool();
        virtual ~Tool() = default;
        
        // virtual methods
        virtual void run() = 0; 
        virtual std::unique_ptr<Tool> clone() const = 0; 

        void setInterface(Interface* iPtr);
        void setUiCanv(UiCanv* uiPtr);
    };
}

#endif