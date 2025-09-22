#include <string>
#include <cstdint>
#include <vector>
#include "cursor.h"

namespace nsk {
    class Sketch {
    private:
        std::vector<std::string> sketch;

        uint16_t xSize;
        uint16_t ySize;
        uint16_t sketchSize;

    public:
        Cursor cursor;
    
        // Constructor
        Sketch(int xSize, int ySize);    

        // Size getters
        const int getXSize() const;
        const int getYSize() const;

        // Change sketch size
        void setSketchSize(int xSize, int ySize);
        
        // Draw methods
        void fillZone();
    };
}