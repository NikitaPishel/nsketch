#ifndef TOOL_BASE_FILL_SLCT
#define TOOL_BASE_FILL_SLCT

#include <memory>
#include "nsketch/interface.h"
#include "nsketch/tool.h"

namespace nsk {
    class FillSlct : public Tool {
    public:
        explicit FillSlct();

        void apply() override;
        std::unique_ptr<Tool> clone() const override;
    };
}

#endif