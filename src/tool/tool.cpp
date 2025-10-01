#include <stdexcept>
#include "nsketch/tool.h"
#include "nsketch/interface.h"
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"

namespace nsk {
    Tool::Tool() : iPtr(nullptr) {}
    
    Sketch& Tool::getSketch() {
        if (this->iPtr == nullptr) {
            throw std::runtime_error("Interface pointer is null. Did you forget to set Interface?");
        }
        
        return this->iPtr->getSketch();
    }
    
    Cursor& Tool::getCursor() {
        if (this->iPtr == nullptr) {
            throw std::runtime_error("Interface pointer is null. Did you forget to set Interface?");
        }
        
        return this->iPtr->getCursor();
    }
    
    Palette& Tool::getPalette() {
        if (this->iPtr == nullptr) {
            throw std::runtime_error("Interface pointer is null. Did you forget to set Interface?");
        }

        return this->iPtr->getPalette();
    }

    void Tool::setInterface(Interface* iPtr) {
        this->iPtr = iPtr;
    }
}