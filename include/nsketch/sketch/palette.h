#ifndef NSKETCH_PALETTE
#define NSKETCH_PALETTE

#include <string>
#include <vector>

namespace nsk {
    class Palette {
    private:
        std::vector<std::string> colors;

        // Primary and Background colors
        std::string primColor;
        std::string backColor;

    public:
        Palette(std::string primColor = "white", std::string backColor = "black");
        
        // Base colors i/o
        void setPrimColor(std::string color);
        void setBackColor(std::string color);
        
        const std::string& getPrimColor();
        const std::string& getBackColor();

        void addColor(std::string color);
        void setColor(int i, std::string color);
        void delColor(int i);
        const std::string& getColor(int i);
    };
}

#endif