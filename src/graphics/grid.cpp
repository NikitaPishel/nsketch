#include <vector>
#include <iostream>
#include <cstdint>
#include <cstring>
#include "gphUtil.h"
#include "grid.h"

namespace gph {
    // Serialized Grid constructor
    GridBuffer::GridBuffer(std::vector<char> buffer): buffer(buffer) {

    }

    // set Pixel instance init values
    Grid::Pixel::Pixel(): symbol(' '), backColor(0), textColor(7) {

    }

    // set Grid instance init values
    Grid::Grid  (int xSize, int ySize): 
    xSize(xSize), 
    ySize(ySize),
    matrix (xSize, std::vector<Pixel>(ySize)) {

    }

    // change grid size
    void Grid::setGridSize(int xSize, int ySize) {
        this->matrix.resize(xSize);

        for (int i = 0; i < xSize; i++) {
            this->matrix[i].resize(ySize);
        }
    }

    // get an access to a pixel (used if you need full control compared to setPixel) or its second version with indirect access
    Grid::Pixel& Grid::getPixel(int xPos, int yPos) {
        return this->matrix[xPos][yPos];
    }

    Grid::Pixel Grid::getPixel(int xPos, int yPos) const {
        return this->matrix[xPos][yPos];
    }

    // update pixel parameters (or add a pixel)
    void Grid::setPixel(int xPos, int yPos, char symbol, int8_t textColor, int8_t backColor) {
        Pixel& slctPixel = this->matrix[xPos][yPos];
        slctPixel.symbol = symbol;
        slctPixel.textColor = textColor;
        slctPixel.backColor = backColor;
    }

    GridBuffer Grid::newBuffer() {
        std::vector<char> binGrid;

        auto append = [&](const void* data, std::size_t size) {
            const char* bytes = reinterpret_cast<const char*>(data);
            binGrid.insert(binGrid.end(), bytes, bytes + size);
        };

        append(&this->xSize, sizeof(this->xSize));
        append(&this->ySize, sizeof(this->ySize));

        for (int y = 0; y < this->ySize; ++y) {
            for (int x = 0; x < this->xSize; ++x) {
                const Grid::Pixel pix = this->getPixel(x, y);
                append(&pix.symbol, sizeof(pix.symbol));
                append(&pix.textColor, sizeof(pix.textColor));
                append(&pix.backColor, sizeof(pix.backColor));
            }
        }
        
        GridBuffer buffer(binGrid);

        return buffer;
    }

    // return unserialized buffer data
    Grid GridBuffer::unpack() {
        std::size_t offset = 0;

        auto read = [&](void* data, std::size_t size) {
            std::memcpy(data, this->buffer.data() + offset, size);
            offset += size;
        };

        int xSize, ySize;
        read(&xSize, sizeof(xSize));
        read(&ySize, sizeof(ySize));

        Grid grid(xSize, ySize);

        for (int y = 0; y < ySize; ++y) {
            for (int x = 0; x < xSize; ++x) {
                char symbol;
                int textColor;
                int backColor;

                read(&symbol, sizeof(symbol));
                read(&textColor, sizeof(textColor));
                read(&backColor, sizeof(backColor));

                grid.setPixel(x, y, symbol, textColor, backColor);
            }
        }

        return grid;
    }

    size_t GridBuffer::getSize() {
        return this->buffer.size();
    }
}

/*
int main() {
    Grid myMatrix(5, 5);
    
    Grid::Pixel* pix1 = myMatrix.getPixel(0, 0);
    Grid::Pixel* pix2 = myMatrix.getPixel(1, 0);
    
    pix1->symbol = '1';
    pix2->symbol = '2';
    
    std::cout << myMatrix.matrix[0][0].symbol << myMatrix.matrix[1][0].symbol << std::endl;
    return 0;
}
*/