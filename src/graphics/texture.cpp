#include <string>
#include "gphUtil.h"
#include "nsketch/gph/texture.h"
#include "grid.h"

namespace gph {

    Texture::Texture(int xSize, int ySize) : grid(xSize, ySize),  colors(Colors::getInstance()) {

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
        int textColorId = this->colors.getColorID(textColor);
            int backColorId = this->colors.getColorID(backColor);

        grid.setPixel(xPos, yPos, symbol, textColorId, backColorId);
    }

    std::vector<char> Texture::serialized() {
        return this->grid.serialized();
    }

}