#include <string>
#include <unordered_map>
#include <stdexcept>
#include "nsketch/tools.h"
#include "nsketch/interface.h"

namespace nsk {
    Interface::Interface() {

    }

    void Interface::linkSketch(Sketch& sketch) {
        this->sPtr = &sketch;
    }

    void Interface::linkCursor(Cursor& cursor) {
        this->cPtr = &cursor;
    }

    Sketch& Interface::getSketch() const {
        return *this->sPtr;
    }
    
    Cursor& Interface::getCursor() const {
        if (!cPtr) {
            throw std::runtime_error("Cursor not linked");
        }

        return *this->cPtr;
    }

    Sketch& Interface::getSketch() const {
        if (!sPtr) {
            throw std::runtime_error("Sketch not linked");
        }

        return *this->sPtr;
    }
    
    Cursor& Interface::getCursor() const {
        return *this->cPtr;
    }

    void Interface::setTool(std::string name, Tool* tool) {

    }

    void Interface::getTool(std::string name) {

    }

    void Interface::delTool(std::string name) {

    }
}