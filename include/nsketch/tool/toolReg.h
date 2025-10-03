#ifndef TOOL_STORE_REG_H
#define TOOL_STORE_REG_H

#include <string>
#include <memory>
#include "nsketch/tool/tool.h"

namespace nsk {
    struct ToolReg {
            ToolReg(const std::string& name, Tool* tool);
            ToolReg(const std::string& name, std::unique_ptr<Tool> tool);
    };
}

#endif