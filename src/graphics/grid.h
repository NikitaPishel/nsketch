#ifndef CANV_GRID_H
#define CANV_GRID_H
#include <vector>
#include <cstdint>

namespace gph {
    // matrix holder class with basic matrix control
    class Grid {
    public:
        // nested struct that holds information about characters in the matrix
        struct Pixel {
            char symbol;
            int textColor; // 16 colors of the basic linux terminal
            int backColor; // same 16 colors

            // struct constructor (for standard member list)
            Pixel();
        };

        // matrix dimensions to exclude constant vector size recall
        int xSize;
        int ySize;

        // Basic control methods
        Grid(int xSize = 0, int ySize = 0);
        void setGridSize(int xSize, int ySize);
        void setPixel(int xPos, int yPos, char symbol = ' ', int textColor = 0, int backColor = 0);
        Pixel* getPixel(int xPos, int yPos);

        // get a serialized copy of a matrix
        std::vector<char> serialized();
        
    private:
        // Pixel grid itself
        std::vector<std::vector<Pixel>> matrix;

    };
}

#endif
