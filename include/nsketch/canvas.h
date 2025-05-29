#ifndef CANVAS_H
#define CANVAS_H
#include "grid.h"

class Canvas {
public:
    Canvas();
    void setSize();
    void updateSize();
    void setPixel();
    void addTexture();

private:
    Grid grid;
};

#endif
