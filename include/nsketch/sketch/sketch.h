#ifndef CKETCH_MAIN_H
#define CKETCH_MAIN_H

#include <string>
#include <cstdint>
#include <vector>
#include <memory>

#include <ngph/texture.h>

using namespace gph;

namespace nsk {
    class Sketch {
    private:
        // Matrix of pixels, pImpl
        Texture::Builder matrix;

        uint16_t xSize;
        uint16_t ySize;
        uint16_t sketchSize;

    public:
        // Constructor
        Sketch(int xSize = 1, int ySize = 1);

        // Size getters
        int getXSize() const;
        int getYSize() const;

        // Change sketch size
        void setSketchSize(int xSize, int ySize);
        
        // Draw methods
        void addPixel(int xPos, int yPos, std::string color);
        void addPixelByIndex(int index, std::string color);
        void fill(int xPos, int yPos, int xSize, int ySize, std::string color);

        // return built version of a sketch
        Texture texturize();
    };
}

#endif