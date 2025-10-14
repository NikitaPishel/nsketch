#ifndef TOOL_BASE_MV_CURSOR
#define TOOL_BASE_MV_CURSOR

#include <memory>
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"

namespace nsk {
    class CursorMvUp : public Tool {
    public:
        explicit CursorMvUp();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };
    
    class CursorMvLeft : public Tool {
    public:
        explicit CursorMvLeft();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };

    class CursorMvDown : public Tool {
    public:
        explicit CursorMvDown();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };

    class CursorMvRight : public Tool {
    public:
        explicit CursorMvRight();

        void run() override;
        std::unique_ptr<Tool> clone() const override;
    };
}

#endif