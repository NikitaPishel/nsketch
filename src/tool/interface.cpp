#include <string>
#include <unordered_map>
#include <stdexcept>
#include "nsketch/tool/tool.h"
#include "nsketch/tool/interface.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/iokey.h"

namespace nsk {
    std::unique_ptr<Tool> EmptyTool::clone() const {
        return std::make_unique<EmptyTool>(*this);
    }

    Interface::Interface() {}

    void Interface::linkSketch(Sketch& sketch) {
        this->sPtr = &sketch;
    }

    void Interface::linkCursor(Cursor& cursor) {
        this->cPtr = &cursor;
    }

    void Interface::linkPalette(Palette& palette) {
        this->pPtr = &palette;
    }

    void Interface::linkUiTex(UiTex& uiTex) {
        this->texPtr = &uiTex;
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

    Palette& Interface::getPalette() const {
        if (!sPtr) {
            throw std::runtime_error("Sketch not linked");
        }

        return *this->pPtr;
    }

    void Interface::addTool(const char& bind, Tool* tool) {
        if (!texPtr) {
            throw std::runtime_error("UiTex not linked");
        }
        
        tool->setInterface(this);
        tool->setUiTex(this->texPtr);
        this->tools[bind] = std::unique_ptr<Tool>(tool);
    }
    
    void Interface::addTool(const char& bind, std::unique_ptr<Tool> tool) {
        if (!texPtr) {
            throw std::runtime_error("UiTex not linked");
        }
        
        tool->setInterface(this);
        tool->setUiTex(this->texPtr);
        this->tools[bind] = std::move(tool);
    }

    Tool& Interface::getTool(const char& bind) {
        auto it = this->tools.find(bind);

        if (it != this->tools.end()) {
            return *it->second;
        }
        
        throw std::runtime_error("Tool not found: " + std::string(1, bind));
    }

    Tool* Interface::getToolPtr(const char& bind) {
        auto it = this->tools.find(bind);

        if (it == this->tools.end()) {
            return nullptr;
        }
        
        return it->second.get();
    }

    void Interface::delTool(const char& bind) {
        this->tools.erase(bind);
    }

    void Interface::addToolFromStore(const char& bind, std::string name) {
        ToolStore& store = ToolStore::getInstance();
        std::unique_ptr tool = store.createTool(name);
        this->addTool(bind, std::move(tool));
    }

    void Interface::runTool(const char& bind) {
        Tool* toolPtr = this->getToolPtr(bind);

        if (!toolPtr) {
            throw std::runtime_error("Unable to run non-existing tool: " + std::string(1, bind));
        }

        toolPtr->run();
    }

    void Interface::autoRunTool() {
        IoKey& ioKey = IoKey::getInstance();

        Tool* toolPtr = this->getToolPtr(ioKey.getChar());

        if (toolPtr) {
            toolPtr->run();
        }
    }
}