#include <string>
#include <vector>
#include <cstdint>
#include "gphUtil.h"
#include "nsketch/gph/texture.h"
#include "grid.h"

namespace gph {
    Texture::Texture(Grid grid) : grid(grid) {

    }

    Texture::~Texture() {
        // Cleanup if necessary
    }

    int Texture::getXSize() const{
        return grid.xSize;
    }

    int Texture::getYSize() const{
        return grid.ySize;
    }

    Grid::Pixel Texture::getPixel(int xPos, int yPos) {
        return this->grid.getPixel(xPos, yPos);
    }

    GridBuffer Texture::newBuffer() const {
        return GridBuffer(this->grid.newBuffer());
    }
}