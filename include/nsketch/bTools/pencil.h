#ifndef TOOL_BASE_PENSIL
#define TOOL_BASE_PENSIL

#include <memory>
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"

namespace nsk {
    class Pencil : public Tool {
    public:
        explicit Pencil();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };
}

#endif