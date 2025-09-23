#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include "nsketch/sketch.h"
#include "matrix.h"
#include "cursor.h"

namespace nsk {
    // Define internal implementation of matrix
    class Sketch::MatrixImpl {
        public:
            Matrix matrix;
            
            MatrixImpl(int xSize, int ySize) : matrix(xSize, ySize) {};
    };
    
    // Define internal implementation of cursor
    class Sketch::CursorImpl {
        public:
            Cursor cursor;

            CursorImpl() : cursor() {};
    };

    // Constructor
    Sketch::Sketch(int xSize, int ySize) :
        mImpl(std::make_unique<MatrixImpl>(xSize, ySize)),
        cImpl(std::make_unique<CursorImpl>())
        {}

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

    }

    // Draw 1 pixel on cursor
    void Sketch::draw() {

    }
}