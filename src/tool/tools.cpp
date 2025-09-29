#include "nsketch/tools.h"
#include "nsketch/interface.h"
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"

namespace nsk {
    Tool::Tool(Interface& interface) : iPtr(&interface) {}
    
    Sketch& Tool::getSketch() {
        return this->iPtr->getSketch();
    }
    
    Cursor& Tool::getCursor() {
        return this->iPtr->getCursor();
    }

    Palette& Tool::getPalette() {
        return this->iPtr->getPalette();
    }
}