#include <stdexcept>
#include <cstdint>
#include <cmath>
#include "cursor.h"

namespace nsk {
    void Cursor::moveCursor(int xPos, int yPos) {
        if (xPos < 0 || yPos < 0) {
            throw std::out_of_range("Cursor position out of range");
        }

        this->xPos = xPos;
        this->yPos = yPos;

        if (zoneSlct) {
            int xShift = xPos - this->xSlct;
            int yShift = yPos - this->ySlct;

            // xSlct changes to be a positive number, xSlctSize adds adds an abslolute to descrive the same area size
            if (xShift < 0) {
                this->xSlctSize += std::abs(xShift);
                this->xSlct = xPos;
            }
            
            // If xShift isn't negative keep xSlct the same and shift xSlctSize to match
            else {
                this->xSlctSize += xShift;
            }
            
            // Same for y; ySlct changes to be a positive number, ySlctSize adds an abslolute to descrive the same area size
            if (yShift < 0) {
                this->ySlctSize += std::abs(yShift);
                this->ySlct = yPos;
            }

            // If yShift isn't negative keep ySlct the same and shift ySlctSize to match
            else {
                this->ySlctSize += yShift;
            }
        }

    }

    const uint16_t Cursor::getCursorX() const {
        return this->xPos;
    }

    const uint16_t Cursor::getCursorY() const {
        return this->yPos;
    }

    void Cursor::setZoneSlct(bool state) {
        // if we switch zone slct to true, update xSlct position
        if (state && !this->zoneSlct) {
            this->xSlct = this->xPos;
            this->ySlct = this->yPos;
        }

        this->ySlctSize = 0;
        this->ySlctSize = 0;
    }

    const bool Cursor::getSlctState() const {
        return this->zoneSlct;
    }
    
    const uint16_t Cursor::getSlctX() const {
        return this->xSlct;
    }
    
    const uint16_t Cursor::getSlctY() const {
        return this->ySlct;
    }
    
    const uint16_t Cursor::getSlctW() const {
        return this->xSlctSize;
    }
    
    const uint16_t Cursor::getSlctH() const {
        return this->ySlctSize;
    }
}