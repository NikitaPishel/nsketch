#ifndef NSKETCH_GPH_IOTEX_H
#define NSKETCH_GPH_IOTEX_H

#include <string>
#include <fstream>
#include <unordered_map>
#include "nsketch/gph/texture.h"

namespace gph {

    class TexTable {
    private:
        // Map of textures; Used to store textures and their later identification by the index.
        std::unordered_map<std::string, Texture> textures;

        std::vector<char> serialize();
        void deserialize(std::vector<char> buffer);
        
    public:
        // Constructor
        TexTable(const std::string& path);

        // Work with binary to save and load textures
        void loadTable(const std::string& path);
        void saveTable(const std::string& path);

        // basic texture map operations
        Texture getTexture(std::string texName);
        void setTexture(std::string texName, Texture texture);
    void delTexture(std::string texName);

    };
}

#endif