#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "gphUtil.h"
#include "grid.h"
#include "nsketch/gph/texture.h"
#include "nsketch/gph/canvas.h"

namespace gph {
    // Canvas constructor
    Canvas::Canvas(uint32_t xSize, uint32_t ySize): canvas(xSize, ySize) {
    }

    // get horizontal canvas size
    uint32_t Canvas::getXSize() {
        return this->canvas.xSize;
    }
    
    // get vertical canvas size
    uint32_t Canvas::getYSize() {
        return this->canvas.ySize;
    }

    uint32_t Canvas::getCanvSize() {
        uint32_t canvSize = this->canvas.xSize * this->canvas.ySize;
        return canvSize;
    }

    // set the canvas size
    void Canvas::setSize(uint32_t xSize, uint32_t ySize) {
        this->canvas.setGridSize(xSize, ySize);
    }

    // automatically set the canvas size to the terminal size
    void Canvas::updateSize() {
        winsize window = getWinSize();
        this->setSize(window.ws_row, window.ws_col);
    }   

    // add a texture to the canvas
    void Canvas::addTexture(uint32_t xPos, uint32_t yPos, Texture newTex) {
        Grid grid = newTex.grid;

        // iterate through indexes of a grid and copy pixels with a shift
        for (int i = 0; i < grid.gridSize; i++) {
            const Grid::Pixel pix = grid.getPixelByIndex(i);

            std::pair<uint32_t, uint32_t> pixPos = grid.getPixelPos(i);
            
            int xShift = pixPos.first + xPos;
            int yShift = pixPos.second + yPos;

            if (xShift < this->getXSize() || yShift < this->getYSize()) {
                this->canvas.addPixel(xShift, yShift, pix);
            }
        }
    }

    // Render and display current canvas
    void Canvas::render() {
        std::string renderedImage;
        
        // reserve space for the string
        // *18 because renderedPix is at max 18 bytes long
        // add y size for each new line ]n
        // add 3 for \033[H at the start of a render (sets cursor to position (0, 0))
        // add 3 for style reset "\033[0m", + 6 in total with \033[H
        size_t renderSize = this->getCanvSize() * 18 + this->getYSize() + 6;
        renderedImage.reserve(renderSize);

        // move cursor to the position (0, 0)
        renderedImage = "\033[H";
        
        // iterate through pixels and find their values
        for (int i = 0; i < this->getCanvSize(); i++) {
            const Grid::Pixel& pix = this->canvas.getPixelByIndex(i);
            
            // format pixel and add it to the rendered image
            renderedImage += "\033[38;5;" + pix.textColor + "48;5;" + pix.backColor + "m" + pix.symbol;
            
            std::pair<uint32_t, uint32_t> pixPos = this->canvas.getPixelPos(i);
            
            // if it is the last pixel in a row, go to a new line
            if (pixPos.second == this->getXSize() - 1) {
                renderedImage += "\n";
            }
        }

        // style reset
        renderedImage += "\033[0m";
        std::cout << renderedImage << std::endl;
    }
}