#include <string>
#include <vector>
#include <cstdint>
#include "gphUtil.h"
#include "nsketch/gph/texture.h"
#include "grid.h"

namespace gph {
    Texture::Texture(int xSize, int ySize) : grid(xSize, ySize) {

    }

    Texture::~Texture() {
        // Cleanup if necessary
    }

    int Texture::getXSize() {
        return grid.xSize;
    }

    int Texture::getYSize() {
        return grid.ySize;
    }

    void Texture::setPixel(int xPos, int yPos, char symbol, std::string textColor, std::string backColor) {
        const Colors& colors = Colors::getInstance();

        int textColorId = colors.getColorID(textColor);
            int backColorId = colors.getColorID(backColor);

        grid.setPixel(xPos, yPos, symbol, textColorId, backColorId);
    }

    void Texture::setPixelByColorId(int xPos, int yPos, char symbol, int8_t textColor, int8_t backColor) {
        grid.setPixel(xPos, yPos, symbol, textColor, backColor);
    }

    void Texture::setGrid(Grid grid) {
        this->grid = grid;
    }

    Grid::Pixel Texture::getPixel(int xPos, int yPos) {
        return this->grid.getPixel(xPos, yPos);
    }

    GridBuffer Texture::newBuffer() {
        return GridBuffer(this->grid.newBuffer());
    }
}