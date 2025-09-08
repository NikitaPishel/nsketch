#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
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
        Grid grid = newTex.grid;

        // iterate through indexes of a grid and copy pixels with a shift
        for (int i = 0; i < grid.gridSize; i++) {
            const Grid::Pixel pix = grid.getPixelByIndex(i);

            std::pair<uint16_t, uint16_t> pixPos = grid.getPixelPos(i);
            
            int xShift = pixPos.first + xPos;
            int yShift = pixPos.second + yPos;

            if (xShift < this->getXSize() || yShift < this->getYSize()) {
                this->canvas.addPixel(xShift, yShift, pix);
            }
        }
    }

    // Render and display current canvas
    void Canvas::render() {
        std::string renderedImage = "";

        for (int i = 0; i < this->getXSize(); i++) {
            const Grid::Pixel pix = this->canvas.getPixelByIndex(i);
            
            std::string renderedPix = "\033[38;5;" + pix.textColor + "48;5;" + pix.backColor + "m" + pix.symbol;
            std::pair<uint16_t, uint16_t> pixPos = this->canvas.getPixelPos(i);
        }
    }
}