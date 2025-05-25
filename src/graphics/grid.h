#ifndef CANV_GRID_H
#define CANV_GRID_H
#include <vector>

struct GridPixel {
    char symbol;
    int textColor; // 16 colors of the basic linux terminal
    int backColor; // same 16 colors
    
};

class Grid
{
private:
    std::vector<std::vector<GridPixel>> matrix;
   
    void fillGrid();

public:
    int xSize;
    int ySize;

    Grid();
    ~Grid();

    void setGridSize();
    void updateGridSize();
    void addPixel();
};

#endif
