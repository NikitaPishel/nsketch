#ifndef CANVAS_H
#define CANVAS_H
#include "grid.h"

class canvas {
public:
    canvas();
    setSize();
    updateSize();
    setPixel();

private:
    int xSize;
    int ySize;
    Grid grid;
};

#endif
