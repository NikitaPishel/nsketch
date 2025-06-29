#include <vector>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include "nsketch/gph/iotex.h"
#include "grid.h"
#include "texture.h"

namespace gph {
    
    TexTable::TexTable(const std::string& path) {
        this->loadTable(path);
    }

    std::vector<char> TexTable::serialize() {
        std::vector<char> buffer;

        auto append = [&](const void* data, std::size_t size) {
            const char* bytes = reinterpret_cast<const char*>(data);
            buffer.insert(buffer.end(), bytes, bytes + size);
        };

        size_t mapSize = textures.size();
        append(&mapSize, sizeof(mapSize));

        for (auto& [key, texture] : textures) {
            size_t keyLen = key.size();
            append(&keyLen, sizeof(keyLen));
            append(key.data(), keyLen);

            GridBuffer texBuffer = texture.newBuffer();
            size_t texSize = texBuffer.getSize();
            append(&texSize, sizeof(texSize));
            append(texBuffer.buffer.data(), texSize);
        }

        return buffer;
    }

    void TexTable::deserialize(std::vector<char> buffer) {
        size_t offset = 0;

        auto read = [&](void* data, std::size_t size) {
            std::memcpy(data, buffer.data() + offset, size);
            offset += size;
        };

        size_t mapSize = 0;
        read(&mapSize, sizeof(mapSize));

        for (size_t i = 0; i < mapSize; ++i) {
            size_t keyLen;
            read(&keyLen, sizeof(keyLen));

            std::string key(keyLen, '\0');
            read(key.data(), keyLen);

            size_t texSize;
            read(&texSize, sizeof(texSize));

            std::vector<char> texData(texSize);
            read(texData.data(), texSize);

            GridBuffer texBuffer(texData);
            Grid grid = texBuffer.unpack();
            Texture texture(grid.xSize, grid.ySize);
            texture.setGrid(grid);

            textures[key] = texture;
        }
    }
    
    void TexTable::loadTable(const std::string& path) {
        std::ifstream file(path, std::ios::binary);
        if (!file) return;

        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        // deserialize method will automatically update the map via loaded buffer
        this->deserialize(buffer);
    }

    void TexTable::saveTable(const std::string& path) {
        std::ofstream file(path, std::ios::binary);
        if (!file) return;

        // serializes current texture map, then writes it into the path
        std::vector<char> buffer = this->serialize();
        file.write(buffer.data(), buffer.size());
        file.close();
    }

    Texture TexTable::getTexture(const std::string texName) {

    }
}