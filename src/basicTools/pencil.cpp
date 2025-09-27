#include "nsketch/bTools/pencil.h"
#include "interface.h"
#include "tools.h"

namespace nsk {
    Pencil::Pencil(Interface& interface) : Tool(interface) {}

    void Pencil::apply() {
        Sketch& sketch = this->getSketch();
        Cursor& cursor = this->getCursor();

        sketch.addPixel(cursor.getCursorX(), cursor.getCursorY(), "white");
    }
}