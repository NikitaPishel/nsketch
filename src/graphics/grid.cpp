#include <vector>
#include <iostream>
#include "gphUtil.h"
#include "grid.h"

using namespace gph;

// set GridPixel instance init values
GridPixel::GridPixel(): symbol(' '), backColor(0), textColor(7) {

};

// set Grid instance init values
Grid::Grid  (int xSize, int ySize): 
xSize(xSize), 
ySize(ySize),
matrix (xSize, std::vector<GridPixel>(ySize)) 
{

};

// change grid size
void Grid::setGridSize(int xSize, int ySize) {
    this->matrix.resize(xSize);

    for (int i = 0; i < xSize; i++) {
        this->matrix[i].resize(ySize);
    };
};

// get a pointer to a pixel (used if you need full control compared to setPixel)
GridPixel* Grid::getPixel(int xPos, int yPos) {
    return &this->matrix[xPos][yPos];
};

// update pixel parameters
void Grid::setPixel(
    int xPos,
    int yPos,
    char symbol = ' ',
    int textColor = 0,
    int backColor = 0
    
) {
    GridPixel& slctPixel = this->matrix[xPos][yPos];
    slctPixel.symbol = symbol;
    slctPixel.textColor = textColor;
    slctPixel.backColor = backColor;
};

/*
int main() {
    Grid myMatrix(5, 5);
    
    GridPixel* pix1 = myMatrix.getPixel(0, 0);
    GridPixel* pix2 = myMatrix.getPixel(1, 0);
    
    pix1->symbol = '1';
    pix2->symbol = '2';
    
    std::cout << myMatrix.matrix[0][0].symbol << myMatrix.matrix[1][0].symbol << std::endl;
    return 0;
};
*/