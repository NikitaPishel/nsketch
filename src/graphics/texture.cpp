#include <string>
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

    std::vector<char> Texture::serialized() {
        return this->grid.serialized();
    }

}