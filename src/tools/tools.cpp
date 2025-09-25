#include "nsketch/tools.h"
#include "nsketch/interface.h"
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"

namespace nsk {
    Tool::Tool(Interface& interface) :
    iPtr(&interface), 
    sketch(this->iPtr->getSketch()),
    cursor(this->iPtr->getCursor()) {}
}