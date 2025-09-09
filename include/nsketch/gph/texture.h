#ifndef CANVAS_TEXTURE_H
#define CANVAS_TEXTURE_H

#include <cstdint>
#include <vector>

namespace gph {
    // class Texture is used to draw blocks of pixels on a canvas
    // it is different from as it is muted and isn't internal for gph
    class Texture {
    private:
        const Grid grid;

    public:
        class Builder {
        private:
            Grid grid;
        
        public:
            Builder(uint32_t xSize, uint32_t ySize);


            // building methods return Builder& instead of void to make chain method calls
            
            // add a single pixel
            Builder& setPixel(int xPos, int yPos, char symbol = ' ', const std::string& textColor = "white", const std::string& backColor = "black");
            
            // fill a zone of a texture
            Builder& fillTexture(char symbol = ' ', const std::string& textColor = "white", const std::string& backColor = "black");
            Builder& fillRow(int yPos, char symbol = ' ', const std::string& textColor = "white", const std::string& backColor = "black");
            Builder& fillCol(int xPos, char symbol = ' ', const std::string& textColor = "white", const std::string& backColor = "black");

            // change size of a texture
            Builder& chnageSize(int xSize, int ySize);

            Texture build();
        };

        // Constructor
        Texture(Grid grid);
        
        // Get texture dimensions
        int getXSize() const;
        int getYSize() const;
        
        // getter method for canvas function
        const Grid& getGrid() const;
        
        // a TexBuffer factory
        GridBuffer newBuffer() const;
    };
}

#endif