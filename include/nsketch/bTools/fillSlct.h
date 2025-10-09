#ifndef TOOL_BASE_FILL_SLCT
#define TOOL_BASE_FILL_SLCT

#include <memory>
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"

namespace nsk {
    class FillSlct : public Tool {
    public:
        explicit FillSlct();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };
}

#endif