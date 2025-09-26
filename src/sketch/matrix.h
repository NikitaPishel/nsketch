#ifndef CANV_GRID_H
#define CANV_GRID_H
#include <vector>
#include <string>
#include <cstdint>

namespace nsk {
    // matrix holder class with basic matrix control
    class Matrix {
        
    public:
        // matrix dimensions to exclude constant vector size recall
        uint32_t xSize;
        uint32_t ySize;
        
        // Basic control methods
        Matrix(int xSize = 0, int ySize = 0);
        void setMatrixSize(int xSize, int ySize);
        
        void setPixel(int xPos, int yPos, std::string color);
        void setPixelByIndex(int index, std::string color);
        
        std::string& getPixel(int xPos, int yPos);
        const std::string& getPixel(int xPos, int yPos) const;
        
        std::string& getPixelByIndex(int index);
        const std::string& getPixelByIndex(int index) const;
        
        // get x and y position of a pixel with index x
        const std::pair<uint32_t, uint32_t> getPixelPos(int index) const;
        
        // total matrix size. Used for internal functionality (indexing)
        uint32_t matrixSize;
        
    private:
        // matrix itself; Vector that works as a projector of a linear indexed matrix
        std::vector<std::string> matrix;
    };
}

#endif
