#include <memory>
#include "nsketch/bTools/pencil.h"
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"
#include "nsketch/tool/toolReg.h"
#include "nsketch/sketch/palette.h"

namespace nsk {
    Pencil::Pencil() : Tool() {}

    void Pencil::run() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();
        Palette& colors = this->getPalette();

        sketch.addPixel(
            cursor.getCursorX(),
            cursor.getCursorY(),
            colors.getPrimColor()
        );
    }

    std::unique_ptr<Tool> Pencil::clone() const {
        return std::make_unique<Pencil>(*this);
    }

    static ToolReg pencilReg("basePencil", std::make_unique<Pencil>());
}