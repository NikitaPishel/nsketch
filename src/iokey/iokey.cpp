#include <termios.h>
#include <cstdio>
#include <unistd.h>
#include "nsketch/iokey.h"

namespace nsk {
    class IoKey::Impl {
    public:
        termios stdTerminal;

        Impl() {};
    };
    
    IoKey::IoKey() : pImpl(std::make_unique<Impl>()) {
        termios& stdTerminal = this->pImpl->stdTerminal;

        // save standard terminal settings
        tcgetattr(STDIN_FILENO, &stdTerminal);
            
        termios newTerminal;
        newTerminal = stdTerminal;
        
        // disable line buffering and echo
        newTerminal.c_lflag &= ~(ICANON | ECHO);

        // setup new terminal
        tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal);
    }

    IoKey::~IoKey() {
        // restore standard terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &this->pImpl->stdTerminal);
    }

    IoKey& IoKey::getInstance() {
        static IoKey instance;
        return instance;
    }

    int IoKey::getCharInt() {
    return std::getchar();
    }

    char IoKey::getChar() {
    return static_cast<char>(getCharInt());
    }
}