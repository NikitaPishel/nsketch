#ifndef CANVAS_TEXTURE_H
#define CANVAS_TEXTURE_H

#include <cstdint>
#include <vector>
#include "grid.h"
#include "gphUtil.h"

namespace gph {
    
    // class Texture is used to draw blocks of pixels on a canvas
    // it is different from grid by typization, static size, setPixel handling and additional methods
    class Texture {
        private:
        Grid grid;
        
        public:
        // Constructor
        Texture(int xSize, int ySize);
        
        // Get texture dimensions
        int getXSize();
        int getYSize();
        
        // Add a pixel to the texture
        void setPixel(int xPos, int yPos, char symbol = ' ', std::string textColor = "white", std::string backColor = "black");
        void setPixelByColorId(int xPos, int yPos, char symbol = ' ', int8_t textColor = 7, int8_t backColor = 0);
        
        // change an existing grid with the new one
        void setGrid(Grid grid);
        
        // get pixel from a grid
        Grid::Pixel getPixel(int xPos, int yPos);
        
        // a TexBuffer factory
        GridBuffer newBuffer();

    };
}

#endif