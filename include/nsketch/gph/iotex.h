#ifndef NSKETCH_GPH_IOTEX_H
#define NSKETCH_GPH_IOTEX_H

#include <string>
#include <fstream>
#include <unordered_map>
#include "nsketch/gph/texture.h"

namespace gph {

    class TexTable {
    public:
        // Constructor
        TexTable();

        // Work with binary to save and load textures
        void loadTable(const std::string& path);
        void saveTable(const std::string& path);

        // Get a texture from textures map
        Texture getTexture(std::string texName);
        
    private:
        // Map of textures; Used to store textures and their later identification by the index.
        std::unordered_map<std::string, Texture> textures;

    };
}

#endif