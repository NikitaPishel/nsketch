#ifndef CANV_GRID_H
#define CANV_GRID_H
#include <vector>

struct GridPixel {
    char symbol;
    int textColor; // 16 colors of the basic linux terminal
    int backColor; // same 16 colors

    GridPixel();
};

class Grid {
private:
    std::vector<std::vector<GridPixel>> matrix;

    void fillGrid();

public:
    int xSize;
    int ySize;

    Grid(int xSize, int ySize);
    void setGridSize(int xSize, int ySize);
    void updateGridSize();
    void setPixel(int xPos, int yPos, char symbol, int textColor, int backColor);

    GridPixel* getPixel(int xPos, int yPos);
};

#endif
