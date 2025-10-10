#include <stdexcept>
#include "nsketch/tool/tool.h"
#include "nsketch/tool/interface.h"
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"

namespace nsk {
    Tool::Tool() : iPtr(nullptr), texPtr(nullptr) {}
    
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

    UiTex& Tool::getUiTex() {
        if (this->texPtr == nullptr) {
            throw std::runtime_error("UI texture pointer is null. Did you forget to set it?");
        }

        return *this->texPtr;
    }

    void Tool::setInterface(Interface* iPtr) {
        this->iPtr = iPtr;
    }

    void Tool::setUiTex(UiTex* texPtr) {
        this->texPtr = texPtr;
    }
}