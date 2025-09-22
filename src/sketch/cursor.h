#ifndef CURSOR_H
#define CURSOR_H

#include <cstdint>

namespace nsk {
    class Cursor {
    private:
        // Position of a cursor on a sketch
        uint16_t xPos;
        uint16_t yPos;
        
        // Zone control (size, pos and state)
        bool zoneSlct;
        uint16_t xSlct;
        uint16_t ySlct;
        uint16_t xSlctSize;
        uint16_t ySlctSize;

    public:
        // Cursor methods
        void moveCursor(int xPos, int yPos);

        const uint16_t getCursorX() const;
        const uint16_t getCursorY() const;

        // Zone select methods
        // When on zone select will be automatically calculated
        void setZoneSlct(bool state);

        const bool getSlctState() const;

        // origin pos of selection
        const uint16_t getSlctX() const;
        const uint16_t getSlctY() const;

        // size of selected zone
        const uint16_t getSlctW() const;
        const uint16_t getSlctH() const;
    };
}

#endif