#ifndef TOOL_BASE_PENSIL
#define TOOL_BASE_PENSIL

#include <memory>
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"

namespace nsk {
    class Eraser : public Tool {
    public:
        explicit Eraser();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };
}

#endif