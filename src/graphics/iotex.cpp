#include "nsketch/gph/iotex.h"
#include "grid.h"
#include <vector>
#include <cstdint>
#include <cstring>
#include <stdexcept>

namespace gph {
    Grid TexTable::deserializeGrid(const std::vector<char>& gridSer) {
    const char* serStart = gridSer.data();
    const char* serEnd = serStart + gridSer.size();

    auto read = [&](auto& value) {
        if (serStart + sizeof(value) > serEnd)
            throw std::runtime_error("Deserialization error: out of bounds");
        std::memcpy(&value, serStart, sizeof(value));
        serStart += sizeof(value);
    };

    int xSize;
    int ySize;

    read(xSize);
    read(ySize);

    Grid grid(xSize, ySize);

    for (int y = 0; y < ySize; ++y) {
        for (int x = 0; x < xSize; ++x) {
            char symbol;
            int textColor;
            int backColor;

            read(symbol);
            read(textColor);
            read(backColor);

            grid.setPixel(x, y, symbol, textColor, backColor);
        }
    }

    return grid;
}

    
    TexTable::TexTable() : textures() {
    }
    
    void TexTable::loadTable(const std::string& path) {
        
    }

    void TexTable::saveTable(const std::string& path) {

    }

    Texture TexTable::getTexture(const std::string texName) {

    }
}