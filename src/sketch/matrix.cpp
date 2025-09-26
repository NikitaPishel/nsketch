#include <vector>
#include <stdexcept>
#include <cstdint>
#include <cstring>
#include "matrix.h"

namespace nsk {
    // set matrix instance init values
    Matrix::Matrix(int xSize, int ySize) {
        if (xSize < 1 || ySize < 1) {
            throw std::invalid_argument("Invalid Matrix size: dimension is below 1");
        }
        
        this->xSize = xSize;
        this->ySize = ySize;
        this->matrixSize = xSize * ySize;

        this->matrix = std::vector<std::string>(this->matrixSize, "0");
    }

    // change matrix size
    void Matrix::setMatrixSize(int xSize, int ySize) {
        if (xSize < 1 || ySize < 1) {
            throw std::invalid_argument("Invalid matrix size: dimension is below 1");
        }
        
        // find new matrix size
        uint32_t matrixSize = xSize*ySize;

        using PixelRecord = std::pair<uint32_t, std::string>;
        uint32_t prjSize = std::min(this->matrixSize, matrixSize);

        // temporary stores projected matrix part (same size as the smallest matrix)
        std::vector<PixelRecord> prjMatrix(prjSize);

        uint32_t oldIndex = 0;

        // loop through old vector and rearrange pixel to keep the same coordinates
        for (uint32_t i = 0; i < prjSize; i++) {

            // calculate pixel x-position based on its old matrix index
            uint32_t xPos = oldIndex % this->xSize;
            
            // check if it is out of range
            if (xPos >= xSize) {
                // calculate new index that will be in range, and find new x-position
                oldIndex = oldIndex - xPos + this->xSize;
                xPos = oldIndex % this->xSize;
            }
            
            // calculate pixel y-position based on its old matrix index
            uint32_t yPos = (oldIndex - xPos) / this->xSize;

            // calculate new pixel index based on its position
            uint32_t newIndex = xSize*yPos + xPos;

            // store pixel in projection list
            std::string pix = this->matrix[oldIndex];
            prjMatrix[i] = {newIndex, pix};
            
            // replace projected pixel from the matrix with blank pixel
            this->matrix[oldIndex] = "black";

            // go to the next index
            oldIndex++;
        }

        this->xSize = xSize;
        this->ySize = ySize;
        this->matrixSize = matrixSize;
        
        this->matrix.resize(matrixSize);

        // project pixels to a new matrix
        for (uint32_t i = 0; i < prjSize; i++) {
            uint32_t newIndex = prjMatrix[i].first;
            std::string pix = prjMatrix[i].second;
            this->matrix[newIndex] = pix;
        }
    }

    // get a reference to the pixel via its coordinates
    std::string& Matrix::getPixel(int xPos, int yPos) {
        if (xPos < 0 || xPos >= xSize || yPos < 0 || yPos >= ySize) {
            throw std::out_of_range("Pixel index out of range.");
        }

        // calculate an index of a pixel in a vector matrix holder
        uint32_t pixIndex = xPos + yPos*xSize;

        return this->matrix[pixIndex];
    }

    // get a const reference to the pixel via its coordinates
    const std::string& Matrix::getPixel(int xPos, int yPos) const {
        if (xPos < 0 || xPos >= xSize || yPos < 0 || yPos >= ySize) {
            throw std::out_of_range("Pixel index out of range.");
        }
        
        uint32_t pixIndex = xPos + yPos*xSize;

        return this->matrix[pixIndex];
    }

    // get a reference to the pixel via relative index
    std::string& Matrix::getPixelByIndex(int index) {
        if (index >= this->matrixSize) {
            throw std::out_of_range("Pixel index out of range.");
        }
        
        return this->matrix[index];
    }
    
    // get a const reference to the pixel via relative index
    const std::string& Matrix::getPixelByIndex(int index) const {
        if (index >= this->matrixSize) {
            throw std::out_of_range("Pixel index out of range.");
        }
        
        return this->matrix[index];
    }
    
    // update pixel parameters (or add a pixel)
    void Matrix::setPixel(int xPos, int yPos, std::string color) {
        if (xPos < 0 || xPos >= xSize || yPos < 0 || yPos >= ySize) {
            throw std::out_of_range("Pixel index out of range.");
        }

        uint16_t index = yPos * this->xSize + xPos;

        this->matrix[index] = color;
    }

    void Matrix::setPixelByIndex(int index, std::string color) {
        if (index < 0 || index >= this->matrixSize) {
            throw std::out_of_range("Pixel index out of range.");
        }
        
        this->matrix[index] = color;
    }

    const std::pair<uint32_t, uint32_t> Matrix::getPixelPos(int index) const {
        if (index < 0 || index >= this->matrixSize) {
            throw std::out_of_range("Pixel index out of range.");
        }

        std::pair<uint32_t, uint32_t> pos;

        pos.first = index % this->xSize;
        pos.second = (index - pos.first) / this->xSize;
        return pos;
    }
}