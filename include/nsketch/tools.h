#ifndef TOOLS_MAIN_H
#define TOOLS_MAIN_H

#include "nsketch/sketch.h"
#include "nsketch/cursor.h"

namespace nsk {
    class Interface;

    class Tool {
    private:
        Interface* iPtr;

    protected:
        Sketch& sketch;
        Cursor& cursor;

    public:
        Tool(Interface& interface);
        virtual ~Tool() = default;

        virtual void apply() = 0;        
    };
}

#endif