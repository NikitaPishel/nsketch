#ifndef TOOL_BASE_PENSIL
#define TOOL_BASE_PENSIL

#include "nsketch/interface.h"
#include "nsketch/tools.h"

namespace nsk {
    class Pencil : public Tool {
    public:
        explicit Pencil(Interface& Interface);

        void apply() override;
    };
}

#endif