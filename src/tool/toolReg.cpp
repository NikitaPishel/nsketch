#include <string>
#include <memory>
#include "nsketch/toolReg.h"
#include "nsketch/toolStore.h"
#include "nsketch/tool.h"

namespace nsk {
    ToolReg::ToolReg(const std::string& name, std::unique_ptr<Tool> tool) {
        ToolStore::getInstance().setTool(name, std::move(tool));
    }

    ToolReg::ToolReg(const std::string& name, Tool* tool) {
        ToolStore::getInstance().setTool(name, tool);
    }
}