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
        Tool& getTool(std::string name);
        void setTool(std::string name, Tool* tool);
        void setTool(std::string name, std::unique_ptr<Tool> tool);
        void delTool(std::string name);
    };
}
#endif