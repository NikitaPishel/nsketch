#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include <ngph/texture.h>
#include <ngph/colors.h>
#include "nsketch/sketch/sketch.h"
#include "nsketch/sketch/cursor.h"

using namespace gph;

namespace nsk {
    // Constructor
    Sketch::Sketch(int xSize, int ySize) :
        matrix(xSize*2, ySize) {}

    // Get x size of a drawing
    int Sketch::getXSize() const {
        return this->matrix.getXSize()/2;
    }

    // Get y size of a drawing
    int Sketch::getYSize() const {
        return this->matrix.getYSize();
    }

    // Change the size of the drawing
    void Sketch::setSketchSize(int xSize, int ySize) {
        this->matrix.setSize(xSize*2, ySize);
    }

    // Add a single pixel to a matrix by coordinates
    void Sketch::addPixel(int xPos, int yPos, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);

        int xPosScaled = xPos*2;

        this->matrix.setPixelById(xPosScaled, yPos, ' ', "7", colorId);
        this->matrix.setPixelById(xPosScaled+1, yPos, ' ', "7", colorId);
    };
    
    // Add a single pixel to a matrix by relative index
    void Sketch::addPixelByIndex(int index, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);

        int matrixIndex = index/2;
        
        this->matrix.setPixelByGridIndex(matrixIndex, ' ', "7", colorId);
        this->matrix.setPixelByGridIndex(matrixIndex+1, ' ', "7", colorId);
    };

    // Fill up the area provided (don't confuse with cursor's zone)
    void Sketch::fill(int xPos, int yPos, int xSize, int ySize, std::string color) {
        this->matrix.addBox(xPos*2, yPos, xSize*2, ySize, ' ', "7", color);
    }
    
    Texture Sketch::texturize() {
        return this->matrix.create();
    }
}