#include "nsketch/bTools/fillSlct.h"
#include "nsketch/interface.h"
#include "nsketch/tools.h"

namespace nsk {
    FillSlct::FillSlct(Interface& interface) : Tool(interface) {}

    void FillSlct::apply() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();

        if (cursor.getSlctState()) {
            sketch.fillZone(
                cursor.getSlctX(),
                cursor.getSlctY(),
                cursor.getSlctW(),
                cursor.getSlctH(),
                "white"
            );
        }

        else {
            sketch.addPixel(
                cursor.getCursorX(),
                cursor.getCursorY(),
                "white"
            );
        }
    }
}