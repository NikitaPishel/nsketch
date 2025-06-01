#ifndef CANVAS_H
#define CANVAS_H
#include "grid.h"
#include "nsketch/gph/texture.h"

namespace gph {
    class Canvas {
        private:
            Grid canvas;

    public:
        // Constructor
        Canvas(int xSize, int ySize);

        // Canvas size
        int getXSize();
        int getYSize();
        void setSize(int xSize, int ySize);
        void updateSize();

        // Adding pixels to the canvas
        void addPixel(int xPos, int yPos, char symbol, int textColor, int backColor);
        void addTexture(int xPos, int yPos);

        // Displaying data
        void render();
    };
};
#endif
