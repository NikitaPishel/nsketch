#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include <ngph/texture.h>
#include <ngph/colors.h>
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"
#include "matrix.h"

using namespace gph;

namespace nsk {
    // Define internal implementation of matrix
    class Sketch::MatrixImpl {
        public:
            Matrix matrix;
            
            MatrixImpl(int xSize, int ySize) : matrix(xSize, ySize) {};
    };

    // Constructor
    Sketch::Sketch(int xSize, int ySize) :
        mImpl(std::make_unique<MatrixImpl>(xSize, ySize)) {}

    // Get x size of a drawing
    int Sketch::getXSize() const {
        return this->mImpl->matrix.xSize;
    }

    // Get y size of a drawing
    int Sketch::getYSize() const {
        return this->mImpl->matrix.xSize;
    }

    // Change the size of the drawing
    void Sketch::setSketchSize(int xSize, int ySize) {
        this->mImpl->matrix.setMatrixSize(xSize, ySize);
    }

    // Add a single pixel to a matrix by coordinates
    void Sketch::addPixel(int xPos, int yPos, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);
        
        this->mImpl->matrix.setPixel(xPos, yPos, colorId);
    };
    
    // Add a single pixel to a matrix by relative index
    void Sketch::addPixelByIndex(int index, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);
        
        this->mImpl->matrix.setPixelByIndex(index, colorId);
    };

    // Fill up the selected zone (if slctZone is on)
    void Sketch::fillZone(int xPos, int yPos, int xSize, int ySize, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);

        for (uint16_t xShift = 0; xShift < xSize; xShift++) {
            for (uint16_t yShift = 0; yShift < ySize; yShift++) {
                uint16_t pixXPos = xPos + xShift;
                uint16_t pixYPos = yPos + yShift;
                
                this->mImpl->matrix.setPixel(pixXPos, pixYPos, colorId);
            }
        }
    }

    // Will be used to display a sketch later
    Texture Sketch::texturize() {
        for (uint16_t i; i < this->mImpl->matrix.matrixSize; i++) {

        }
    }
}