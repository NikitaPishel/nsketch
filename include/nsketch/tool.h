#ifndef TOOLS_MAIN_H
#define TOOLS_MAIN_H

#include "nsketch/sketch.h"
#include "nsketch/cursor.h"
#include "nsketch/palette.h"
#include "nsketch/interface.h"

namespace nsk {
    class Interface;

    class Tool {
    private:
        Interface* iPtr;

    protected:
        Sketch& getSketch();
        Cursor& getCursor();
        Palette& getPalette();
        
    public:
        explicit Tool();
        virtual ~Tool() = default;
        
        virtual void apply() = 0; 

        void setInterface(Interface& interface);
    };
}

#endif