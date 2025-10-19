#include <memory>
#include "nsketch/bTools/eraser.h"
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"
#include "nsketch/tool/toolReg.h"
#include "nsketch/sketch/palette.h"
#include "nsketch/appManager.h"

namespace nsk {
    Eraser::Eraser() : Tool() {}

    void Eraser::run() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();
        Palette& colors = this->getPalette();
        UiCanv& ui = this->getUiCanv();
        
        sketch.addPixel(
            cursor.getCursorX(),
            cursor.getCursorY(),
            colors.getBackColor()
        );

        ui.updateSketch();
    }

    std::unique_ptr<Tool> Eraser::clone() const {
        return std::make_unique<Eraser>(*this);
    }

    static ToolReg pencilReg("baseEraser", std::make_unique<Eraser>());
}