#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "gphUtil.h"
#include "grid.h"
#include "nsketch/gph/texture.h"
#include "nsketch/gph/canvas.h"

namespace gph {

    class Canvas::Impl {
    public:
        Grid canvas;

        Impl(Grid canvas) : canvas(canvas) {};
    };

    // Canvas constructor; Makes a unique_ptr of Impl with Grid sized (xSize, ySize)
    Canvas::Canvas(int xSize, int ySize) : pImpl(std::make_unique<Impl>(Grid(xSize, ySize))) {}

    // default destructor
    Canvas::~Canvas() = default;

    // get horizontal canvas size
    uint32_t Canvas::getXSize() const {
        return this->pImpl->canvas.xSize;
    }
    
    // get vertical canvas size
    uint32_t Canvas::getYSize() const {
        return this->pImpl->canvas.ySize;
    }

    uint32_t Canvas::getCanvSize() const {
        return this->pImpl->canvas.gridSize;
    }

    // set the canvas size
    void Canvas::setSize(int xSize, int ySize) {
        this->pImpl->canvas.setGridSize(xSize, ySize);
    }

    // automatically set the canvas size to the terminal size
    void Canvas::updateSize() {
        winsize window = getWinSize();
        int xSize = window.ws_col;
        int ySize = window.ws_row;

        if (xSize < 1) {
            xSize = 1;
        }
        
        if (ySize < 1) {
            ySize = 1;
        }

        this->setSize(xSize, ySize);
    }   

    void Canvas::setPixel(int xPos, int yPos, char symbol, std::string textColor, std::string backColor) {
        const Colors& colors = Colors::getInstance();
        std::string textColorId = colors.getColorId(textColor);
        std::string backColorId = colors.getColorId(backColor);

        this->pImpl->canvas.setPixel(xPos, yPos, symbol, textColorId, backColorId);
    }

    // add a texture to the canvas
    void Canvas::addTexture(int xPos, int yPos, const Texture& newTex) {
        if (xPos < 0 || yPos < 0) {
            throw std::out_of_range("Texture position out of range (below 0)");
        }

        if (xPos >= this->getXSize() || yPos >= this->getYSize()) {
            throw std::out_of_range("Texture position out of range (overflow)");
        }
        
        const Grid& grid = newTex.getGrid();

        // iterate through indexes of a grid and copy pixels with a shift
        for (int i = 0; i < grid.gridSize; i++) {
            const Grid::Pixel pix = grid.getPixelByIndex(i);
            
            std::pair<uint32_t, uint32_t> pixPos = grid.getPixelPos(i);

            uint32_t xShift = pixPos.first + xPos;
            uint32_t yShift = pixPos.second + yPos;

            if (xShift < this->getXSize() && yShift < this->getYSize()) {
                this->pImpl->canvas.addPixel(xShift, yShift, pix);
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
            const Grid::Pixel& pix = this->pImpl->canvas.getPixelByIndex(i);
            
            // format pixel and add it to the rendered image
            renderedImage += "\033[38;5;" + pix.textColor + "48;5;" + pix.backColor + "m" + pix.symbol;
            
            std::pair<uint32_t, uint32_t> pixPos = this->pImpl->canvas.getPixelPos(i);
            
            // if it is the last pixel in a row, go to a new line
            if (pixPos.first == this->getXSize() - 1) {
                renderedImage += "\n";
            }
        }

        // style reset
        renderedImage += "\033[0m";
        std::cout << renderedImage << std::endl;
    }
}