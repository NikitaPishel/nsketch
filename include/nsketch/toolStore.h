#ifndef STORE_TOOLS_H
#define STORE_TOOLS_H

#include <unordered_map>
#include <memory>
#include "nsketch/tool.h"

namespace nsk {
    class ToolStore {
    private:
        // global map of tools
        std::unordered_map<std::string, std::unique_ptr<Tool>> tools;
    
    public:
        // Singleton instance method
        static ToolStore& getInstance();

        // Tools i/o
        std::unique_ptr<Tool> createTool(const std::string& name);
        void setTool(const std::string& name, Tool* tool);
        void setTool(const std::string& name, std::unique_ptr<Tool> tool);
        void delTool(const std::string& name);
    };
}
#endif