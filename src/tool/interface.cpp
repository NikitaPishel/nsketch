#include <string>
#include <unordered_map>
#include <stdexcept>
#include "nsketch/tool/tool.h"
#include "nsketch/tool/interface.h"
#include "nsketch/tool/toolStore.h"

namespace nsk {
    std::unique_ptr<Tool> EmptyTool::clone() const {
        return std::make_unique<EmptyTool>(*this);
    }

    Interface::Interface() {

    }

    void Interface::linkSketch(Sketch& sketch) {
        this->sPtr = &sketch;
    }

    void Interface::linkCursor(Cursor& cursor) {
        this->cPtr = &cursor;
    }

    void Interface::linkPalette(Palette& palette) {
        this->pPtr = &palette;
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

    void Interface::addTool(const std::string& name, Tool* tool) {
        tool->setInterface(this);
        this->tools[name] = std::unique_ptr<Tool>(tool);
    }

    void Interface::addTool(const std::string& name, std::unique_ptr<Tool> tool) {
        tool->setInterface(this);
        this->tools[name] = std::move(tool);
    }

    Tool& Interface::getTool(const std::string& name) {
        auto it = this->tools.find(name);

        if (it != this->tools.end()) {
            return *it->second;
        }
        
        throw std::runtime_error("Tool not found: " + name);
    }

    void Interface::delTool(const std::string& name) {
        this->tools.erase(name);
    }

    void Interface::addToolFromStore(const std::string& name) {
        ToolStore& store = ToolStore::getInstance();
        std::unique_ptr tool = store.createTool(name);
        this->addTool(name, std::move(tool));
    }

    void Interface::useTool(const std::string& name) {
        this->getTool(name).run();
    }
}