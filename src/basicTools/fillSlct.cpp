#include "nsketch/bTools/fillSlct.h"
#include "nsketch/interface.h"
#include "nsketch/tool.h"

namespace nsk {
    FillSlct::FillSlct(Interface& interface) : Tool(interface) {}

    void FillSlct::apply() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();
        Palette& colors = this->getPalette();

        if (cursor.getSlctState()) {
            sketch.fillZone(
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
}