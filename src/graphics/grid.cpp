#include <vector>
#include <iostream>
#include "gphUtil.h"
#include "grid.h"

namespace gph {
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

    // get a pointer to a pixel (used if you need full control compared to setPixel)
    Grid::Pixel* Grid::getPixel(int xPos, int yPos) {
        return &this->matrix[xPos][yPos];
    }

    // update pixel parameters (or add a pixel)
    void Grid::setPixel(int xPos, int yPos, char symbol, int textColor, int backColor) {
        Pixel& slctPixel = this->matrix[xPos][yPos];
        slctPixel.symbol = symbol;
        slctPixel.textColor = textColor;
        slctPixel.backColor = backColor;
    }

    std::vector<char> Grid::serialized() {
        std::vector<char> buffer;

        auto append = [&](const void* data, std::size_t size) {
            const char* bytes = reinterpret_cast<const char*>(data);
            buffer.insert(buffer.end(), bytes, bytes + size);
        };

        append(&this->xSize, sizeof(this->xSize));
        append(&this->ySize, sizeof(this->ySize));

        for (int y = 0; y < this->ySize; ++y) {
            for (int x = 0; x < this->xSize; ++x) {
                const Grid::Pixel* p = this->getPixel(x, y);
                append(&p->symbol, sizeof(p->symbol));
                append(&p->textColor, sizeof(p->textColor));
                append(&p->backColor, sizeof(p->backColor));
            }
        }

        return buffer;
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