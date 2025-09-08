#ifndef CANVAS_TEXTURE_H
#define CANVAS_TEXTURE_H

#include <cstdint>
#include <vector>
#include "grid.h"
#include "gphUtil.h"

namespace gph {
    
    // class Texture is used to draw blocks of pixels on a canvas
    // it is different from grid by typization, static size, and const matrix
    class Texture {
    public:
        const Grid grid;

        // Constructor
        Texture(Grid grid);
        
        // Get texture dimensions
        int getXSize() const;
        int getYSize() const;
        
        // get pixel from a grid
        Grid::Pixel getPixel(int xPos, int yPos);
        
        // a TexBuffer factory
        GridBuffer newBuffer() const;

    };
}

#endif