#include "nsketch/bTools/pencil.h"
#include "nsketch/interface.h"
#include "nsketch/tools.h"
#include "nsketch/palette.h"

namespace nsk {
    Pencil::Pencil(Interface& interface) : Tool(interface) {}

    void Pencil::apply() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();
        Palette& colors = this->getPalette();

        sketch.addPixel(
            cursor.getCursorX(),
            cursor.getCursorY(),
            colors.getPrimColor()
        );
    }
}