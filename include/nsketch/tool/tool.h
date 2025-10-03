#ifndef TOOLS_MAIN_H
#define TOOLS_MAIN_H

#include <memory>
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"
#include "nsketch/sketch/palette.h"

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
        
        // virtual methods
        virtual void apply() = 0; 
        virtual std::unique_ptr<Tool> clone() const = 0; 

        void setInterface(Interface* iPtr);
    };
}

#endif