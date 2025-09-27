#ifndef TOOL_BASE_PENSIL
#define TOOL_BASE_PENSIL

#include "interface.h"
#include "tools.h"

namespace nsk {
    class Pencil : public Tool {
    public:
        explicit Pencil(Interface& Interface);

        void apply() override;
    };
}

#endif