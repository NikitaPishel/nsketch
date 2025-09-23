#include <string>
#include <cstdint>
#include <vector>
#include <memory>

namespace nsk {
    class Sketch {
    private:
        // Matrix of pixels, pImpl
        class MatrixImpl; 
        std::unique_ptr<MatrixImpl> mImpl;

        uint16_t xSize;
        uint16_t ySize;
        uint16_t sketchSize;

    public:
        // Create a cursor of a sketch, pImpl
        class CursorImpl;
        std::unique_ptr<CursorImpl> cImpl;
    
        // Constructor
        Sketch(int xSize = 1, int ySize = 1);

        // Size getters
        int getXSize() const;
        int getYSize() const;

        // Change sketch size
        void setSketchSize(int xSize, int ySize);
        
        // Draw methods
        void fillZone();
        void draw();
    };
}