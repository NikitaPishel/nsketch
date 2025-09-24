#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include "nsketch/sketch.h"
#include "matrix.h"
#include "nsketch/cursor.h"

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

    void Sketch::linkCursor(Cursor& cursor) {
        this->cursor = &cursor;
    }

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

    // Fill up the selected zone (if slctZone is on)
    void Sketch::fillZone() {
        for (uint16_t xShift = 0; xShift < this->cursor->getSlctW(); xShift++) {
            for (uint16_t yShift = 0; yShift < this->cursor->getSlctH(); yShift++) {
                uint16_t xPos = xShift + this->cursor->getSlctX();
                uint16_t yPos = yShift + this->cursor->getSlctY();
                
                this->mImpl->matrix.addPixel(xShift, yShift, "black");
            }
        }
    }

    // Draw 1 pixel on cursor
    void Sketch::draw() {
        this->mImpl->matrix.addPixel(
            this->cursor->getCursorX(),
            this->cursor->getCursorY(),
            "black"
        );
    }
}