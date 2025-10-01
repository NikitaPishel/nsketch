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
    void ToolStore::setTool(const std::string& name, Tool* tool) {
        this->tools[name] = std::unique_ptr<Tool>(tool);
    }

    void ToolStore::setTool(const std::string& name, std::unique_ptr<Tool> tool) {
        this->tools[name] = std::move(tool);
    }

    void ToolStore::delTool(const std::string& name) {
        this->tools.erase(name);
    }

    std::unique_ptr<Tool> ToolStore::createTool(const std::string& name) {
        auto it = this->tools.find(name);

        if (it == this->tools.end()) {
            throw std::runtime_error("Tool not found: " + name);
        }

        return it->second->clone();
    }
}