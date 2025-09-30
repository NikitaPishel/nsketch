#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include <ngph/texture.h>
#include <ngph/colors.h>
#include "nsketch/sketch.h"
#include "nsketch/cursor.h"

using namespace gph;

namespace nsk {
    // Constructor
    Sketch::Sketch(int xSize, int ySize) :
        matrix(xSize, ySize) {}

    // Get x size of a drawing
    int Sketch::getXSize() const {
        return this->matrix.getXSize();
    }

    // Get y size of a drawing
    int Sketch::getYSize() const {
        return this->matrix.getYSize();
    }

    // Change the size of the drawing
    void Sketch::setSketchSize(int xSize, int ySize) {
        this->matrix.setSize(xSize, ySize);
    }

    // Add a single pixel to a matrix by coordinates
    void Sketch::addPixel(int xPos, int yPos, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);

        this->matrix.setPixelById(xPos, yPos, ' ', "white", colorId);
    };
    
    // Add a single pixel to a matrix by relative index
    void Sketch::addPixelByIndex(int index, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);
        
        this->matrix.setPixelByGridIndex(index, ' ', "white", colorId);
    };

    // Fill up the selected zone (if slctZone is on)
    void Sketch::fillZone(int xPos, int yPos, int xSize, int ySize, std::string color) {
        const Colors& gphColors = Colors::getInstance();
        std::string colorId = gphColors.getColorId(color);

        for (uint16_t xShift = 0; xShift < xSize; xShift++) {
            for (uint16_t yShift = 0; yShift < ySize; yShift++) {
                uint16_t pixXPos = xPos + xShift;
                uint16_t pixYPos = yPos + yShift;
                
                this->matrix.setPixelById(pixXPos, pixYPos, ' ', "white", colorId);
            }
        }
    }
}