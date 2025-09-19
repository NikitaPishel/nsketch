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

        uint16_t getCursorX();
        uint16_t getCursorY();

        // Zone select methods
        // When on zone select will be automatically calculated
        void setZoneSlct(bool state);

        // origin pos of selection
        uint16_t getSlctX();
        uint16_t getSlctY();

        // size of selected zone
        uint16_t getSlctW();
        uint16_t getSlctH();
    };
}

#endif