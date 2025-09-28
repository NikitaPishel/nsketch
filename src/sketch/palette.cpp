#include <string>
#include <vector>
#include "nsketch/palette.h"

namespace nsk {
    Palette::Palette(std::string primColor, std::string backColor) :
    primColor(primColor),
    backColor(backColor) {}

    void Palette::setPrimColor(std::string color) {
        this->primColor = color;
    }
    
    void Palette::setBackColor(std::string color) {
        this->backColor = color;
    }

    const std::string& Palette::getPrimColor() {
        return this->primColor;
    }
    
    const std::string& Palette::getBackColor() {
        return this->backColor;
    }

    void Palette::addColor(std::string color) {
        this->colors.push_back(color);
    }

    void Palette::setColor(int i, std::string color) {
        this->colors[i] = color;
    }
    void Palette::delColor(int i) {
        this->colors.pop_back();
    }

    const std::string& Palette::getColor(int i) {
        return this->colors[i];
    }
}