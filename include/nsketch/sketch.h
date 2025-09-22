#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include "cursor.h"

namespace nsk {
    class Sketch {
    private:
        // hidden matrix implementation
        class Impl; 
        std::unique_ptr<Impl> pImpl;

        uint16_t xSize;
        uint16_t ySize;
        uint16_t sketchSize;

    public:
        // Create a cursor of a sketch
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