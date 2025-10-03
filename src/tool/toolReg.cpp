#include <string>
#include <memory>
#include "nsketch/tool/toolReg.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/tool/tool.h"

namespace nsk {
    ToolReg::ToolReg(const std::string& name, std::unique_ptr<Tool> tool) {
        ToolStore::getInstance().setTool(name, std::move(tool));
    }

    ToolReg::ToolReg(const std::string& name, Tool* tool) {
        ToolStore::getInstance().setTool(name, tool);
    }
}