#ifndef IOKEY_MAIN_H
#define IOKEY_MAIN_H

#include <memory>

namespace nsk {
    class IoKey {
    private:
        // internal implementation
        class Impl;
        std::unique_ptr<Impl> pImpl;

        // flag that checks if character has been captured
        bool captured;

        // stores character
        int buffer;

        IoKey();
        ~IoKey();
        
        bool keyPressed();
        
    public:
        // delete copy/move operators
        IoKey(const IoKey&) = delete; 
        IoKey& operator=(const IoKey) = delete; 
        IoKey(IoKey&&) = delete;
        IoKey& operator=(IoKey&&) = delete;
        
        static IoKey& getInstance();

        int getCharInt();
        char getChar();

        void resetCapture();

    };
}

#endif