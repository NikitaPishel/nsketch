#include <string>
#include <vector>
#include <cstdint>
#include "gphUtil.h"
#include "nsketch/gph/texture.h"
#include "grid.h"

namespace gph {

    // Builder constructor
    Texture::Builder::Builder(uint32_t xSize,uint32_t ySize ) {
        
    }

    // just uses gphUtil to use grid's setPixel
    Texture::Builder& Texture::Builder::setPixel(int xPos, int yPos, char symbol, const std::string& textColor, const std::string& backColor) {
        const Colors& colors = Colors::getInstance();
        std::string textColorId = colors.getColorId(textColor);
        std::string backColorId = colors.getColorId(backColor);

        this->grid.setPixel(xPos, yPos, symbol, textColorId, backColorId);

        // pointer for chain method calls
        return *this;
    }
    
    // fill the whole grid with the same pixel
    Texture::Builder& Texture::Builder::fillTexture(char symbol, const std::string& textColor, const std::string& backColor) {
        const Colors& colors = Colors::getInstance();
        std::string textColorId = colors.getColorId(textColor);
        std::string backColorId = colors.getColorId(backColor);

        Grid::Pixel pix;
        pix.symbol = symbol;
        pix.textColor = textColorId;
        pix.backColor = backColorId;
        
        for (uint32_t i = 0; i < this->grid.gridSize; i++) {
            this->grid.getPixelByIndex(i) = pix;
        }

        // pointer for chain method calls
        return *this;
    }
    
    // fill a chosen row with the same pixel
    Texture::Builder& Texture::Builder::fillRow(int yPos, char symbol, const std::string& textColor, const std::string& backColor){
        const Colors& colors = Colors::getInstance();
        std::string textColorId = colors.getColorId(textColor);
        std::string backColorId = colors.getColorId(backColor);
        
        
        Grid::Pixel pix;
        pix.symbol = symbol;
        pix.textColor = textColorId;
        pix.backColor = backColorId;
        
        for (uint32_t i = 0; i < this->grid.xSize; i++) {
            this->grid.getPixel(i, yPos) = pix;
        }
        
        // pointer for chain method calls
        return *this;
    }
    
    // fill a chosen column with the same pixel
    Texture::Builder& Texture::Builder::fillCol(int xPos, char symbol, const std::string& textColor, const std::string& backColor) {
        const Colors& colors = Colors::getInstance();
        std::string textColorId = colors.getColorId(textColor);
        std::string backColorId = colors.getColorId(backColor);

        Grid::Pixel pix;
        pix.symbol = symbol;
        pix.textColor = textColorId;
        pix.backColor = backColorId;
        
        for (uint32_t i = 0; i < this->grid.ySize; i++) {
            this->grid.getPixel(xPos, i) = pix;
        }

        // pointer for chain method calls
        return *this;
    }
    
    // change the size of a grid
    Texture::Builder& Texture::Builder::chnageSize(int xSize, int ySize) {
        this->grid.setGridSize(xSize, ySize);
        
        // pointer for chain method calls
        return *this;
    }
    
    Texture Texture::Builder::build() {
        return Texture(this->grid);
    }

    Texture::Texture(Grid grid) {
        
    }
    
    int Texture::getXSize() const{
        return grid.xSize;
    }
    
    int Texture::getYSize() const{
        return grid.ySize;
    }
    
    const Grid& Texture::getGrid() const {
        return this->grid;
    }
    
    GridBuffer Texture::newBuffer() const {
        return GridBuffer(this->grid.newBuffer());
    }
}