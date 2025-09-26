#ifndef CKETCH_MAIN_H
#define CKETCH_MAIN_H

#include <string>
#include <cstdint>
#include <vector>
#include <memory>

#include <ngph/texture.h>


namespace nsk {
    class Sketch {
    private:
        // Matrix of pixels, pImpl
        class MatrixImpl; 
        std::unique_ptr<MatrixImpl> mImpl;

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
        void fillZone(int xPos, int yPos, int xSize, int ySize, std::string color);

        // Return a texture representation of a sketch
        gph::Texture texturize();
    };
}

#endif