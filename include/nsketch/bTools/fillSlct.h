#ifndef TOOL_BASE_FILL_SLCT
#define TOOL_BASE_FILL_SLCT

#include "interface.h"
#include "tools.h"

namespace nsk {
    class FillSlct : public Tool {
    public:
        explicit FillSlct(Interface& Interface);

        void apply() override;
    };
}

#endif