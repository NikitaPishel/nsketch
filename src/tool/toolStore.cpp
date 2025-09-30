#include <unordered_map>
#include "nsketch/toolStore.h"
#include "nsketch/tool.h"
#include <stdexcept>

namespace nsk {
    // Singleton getter
    ToolStore& ToolStore::getInstance() {
        static ToolStore store;
        return store;
    }

    // Tools store i/o
    void ToolStore::setTool(std::string name, Tool* tool) {
        this->tools[name] = std::unique_ptr<Tool>(tool);
    }

    void ToolStore::setTool(std::string name, std::unique_ptr<Tool> tool) {
        this->tools[name] = std::move(tool);
    }

    Tool& ToolStore::getTool(std::string name) {
        auto it = this->tools.find(name);

        if (it != this->tools.end()) {
            return *it->second;
        }
        
        throw std::runtime_error("Tool not found: " + name);
    }

    void ToolStore::delTool(std::string name) {
        this->tools.erase(name);
    }
}