#ifndef CANVAS_TEXTURE_H
#define CANVAS_TEXTURE_H
#include "grid.h"
#include "gphUtil.h"

namespace gph {
    // class Texture is used to draw blocks of pixels on a canvas
    // there is no setSize, so it is encapsulated from size changes
    class Texture {
    private:
        Grid grid;
        const Colors& colors; // as it uses colors singleton

    public:
        // Constructor
        Texture(int xSize, int ySize);

        // Get texture dimensions
        int getXSize();
        int getYSize();

        // Add a pixel to the texture
        void setPixel(int xPos, int yPos, char symbol = ' ', std::string textColor = "white", std::string backColor = "black");
    };
}

#endif