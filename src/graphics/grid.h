#ifndef CANV_GRID_H
#define CANV_GRID_H
#include <vector>

namespace gph {
    class Grid {
    public:
        int xSize;
        int ySize;

        Grid(int xSize = 0, int ySize = 0);
        void setGridSize(int xSize, int ySize);
        void setPixel(int xPos, int yPos, char symbol = ' ', int textColor = 0, int backColor = 0);

        struct GridPixel {
            char symbol;
            int textColor; // 16 colors of the basic linux terminal
            int backColor; // same 16 colors

            GridPixel();
        };

        GridPixel* getPixel(int xPos, int yPos);
        
    private:
        std::vector<std::vector<GridPixel>> matrix;

    };
}

#endif
