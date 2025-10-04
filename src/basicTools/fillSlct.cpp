#include <memory>
#include <string>
#include "nsketch/bTools/fillSlct.h"
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"
#include "nsketch/tool/toolReg.h"
#include "nsketch/sketch/palette.h"

namespace nsk {
    FillSlct::FillSlct() : Tool() {}

    void FillSlct::apply() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();
        Palette& colors = this->getPalette();

        if (cursor.getSlctState()) {
            sketch.fill(
                cursor.getSlctX(),
                cursor.getSlctY(),
                cursor.getSlctW(),
                cursor.getSlctH(),
                colors.getPrimColor()
            );
        }

        else {
            sketch.addPixel(
                cursor.getCursorX(),
                cursor.getCursorY(),
                colors.getPrimColor()
            );
        }
    }

    std::unique_ptr<Tool> FillSlct::clone() const {
        return std::make_unique<FillSlct>(*this);
    }

    static ToolReg fillSlct("baseFillSlct", std::make_unique<FillSlct>());
}