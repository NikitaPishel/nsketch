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

    // Fill up the area provided (don't confuse with cursor's zone)
    void Sketch::fill(int xPos, int yPos, int xSize, int ySize, std::string color) {
        this->matrix.addBox(xPos, yPos, xSize, ySize, ' ', "white", color);
    }
    
    Texture Sketch::texturize() {
        return this->matrix.create();
    }
}