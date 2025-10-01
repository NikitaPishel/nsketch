#ifndef TOOL_BASE_PENSIL
#define TOOL_BASE_PENSIL

#include "nsketch/interface.h"
#include "nsketch/tool.h"

namespace nsk {
    class Pencil : public Tool {
    public:
        explicit Pencil();

        void apply() override;
    };
}

#endif