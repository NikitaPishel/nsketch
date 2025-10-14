#ifndef CURSOR_H
#define CURSOR_H

#include <cstdint>

namespace nsk {
    class Cursor {
    private:
        // Position of a cursor on a sketch
        uint16_t xPos = 0;
        uint16_t yPos = 0;
        
        // Zone control (size, pos and state)
        bool zoneSlct = false;
        uint16_t xSlct = 0;
        uint16_t ySlct = 0;
        uint16_t xSlctSize = 0;
        uint16_t ySlctSize = 0;

    public:
        Cursor();

        // Cursor methods
        void moveCursor(int xPos, int yPos);
        void shiftCursor(int xShift, int yShift);

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