#include <sys/ioctl.h>
#include <unistd.h>
#include "gphUtil.h"
#include "grid.h"
#include "nsketch/gph/texture.h"
#include "nsketch/gph/canvas.h"

namespace gph {
    // Canvas constructor
    Canvas::Canvas(int xSize, int ySize): canvas(xSize, ySize) {
    }

    // get horizontal canvas size
    int Canvas::getXSize() {
        return this->canvas.xSize;
    }
    
    // get vertical canvas size
    int Canvas::getYSize() {
        return this->canvas.ySize;
    }

    // set the canvas size
    void Canvas::setSize(int xSize, int ySize) {
        this->canvas.setGridSize(xSize, ySize);
    }

    // automatically set the canvas size to the terminal size
    void Canvas::updateSize() {
        winsize window = getWinSize();
        this->setSize(window.ws_row, window.ws_col);
    }   

    // add a texture to the canvas
    void Canvas::addTexture(int xPos, int yPos, Texture newTex) {
        for (int xShift = 0; xShift > newTex.getXSize(); xShift++) {
            for (int yShift = 0; yShift > newTex.getYSize(); yShift++) {
                this->canvas.getPixel(xPos+xShift, yPos+yShift);
                this->canvas.getPixel(xPos+xShift, yPos+yShift);
            }
        }
    }

    // Render and display current canvas
    void Canvas::render() {

    }
}