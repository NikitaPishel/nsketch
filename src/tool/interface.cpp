#include <string>
#include <unordered_map>
#include <stdexcept>
#include "nsketch/tools.h"
#include "nsketch/interface.h"

namespace nsk {
    // Empty tool child for creating empty tools in an interface
    class EmptyTool : public Tool {
    public:
        EmptyTool(Interface& iface) : Tool(iface) {}
        void apply() override {} // does nothing
    };

    Interface::Interface() {

    }

    void Interface::linkSketch(Sketch& sketch) {
        this->sPtr = &sketch;
    }

    void Interface::linkCursor(Cursor& cursor) {
        this->cPtr = &cursor;
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

    void Interface::setTool(std::string name, Tool* tool) {
        this->tools[name] = std::unique_ptr<Tool>(tool);
    }

    void Interface::setTool(std::string name, std::unique_ptr<Tool> tool) {
        this->tools[name] = std::move(tool);
    }

    Tool& Interface::getTool(std::string name) {
        auto it = this->tools.find(name);

        if (it != this->tools.end()) {
            return *it->second;
        }
        
        throw std::runtime_error("Tool not found: " + name);
    }

    void Interface::delTool(std::string name) {
        this->tools.erase(name);
    }
}