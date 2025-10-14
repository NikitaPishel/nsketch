#include <stdexcept>
#include "nsketch/tool/tool.h"
#include "nsketch/tool/interface.h"
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"

namespace nsk {
    Tool::Tool() : iPtr(nullptr), uiPtr(nullptr) {}
    
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

    UiCanv& Tool::getUiCanv() {
        if (this->uiPtr == nullptr) {
            throw std::runtime_error("UI canvas pointer is null. Did you forget to set it?");
        }

        return *this->uiPtr;
    }

    void Tool::setInterface(Interface* iPtr) {
        this->iPtr = iPtr;
    }

    void Tool::setUiCanv(UiCanv* uiPtr) {
        this->uiPtr = uiPtr;
    }
}