#ifndef CANVAS_H
#define CANVAS_H
#include <string>
#include "grid.h"
#include "nsketch/gph/texture.h"

namespace gph {
    class Canvas {
    private:
        Grid canvas;

    public:
        // Constructor
        Canvas(uint32_t xSize, uint32_t ySize);

        // Canvas size
        uint32_t getXSize();
        uint32_t getYSize();
        uint32_t getCanvSize();
        void setSize(uint32_t xSize, uint32_t ySize);
        void updateSize();

        // Adding pixels to the canvas
        void addPixel(uint32_t xPos, uint32_t yPos, Grid::Pixel pixel);
        void setPixel(uint32_t xPos, uint32_t yPos, char symbol, std::string textColor, std::string backColor);
        void addTexture(uint32_t xPos, uint32_t yPos, Texture newTex);

        // render and display data
        void render();
    };
};
#endif
