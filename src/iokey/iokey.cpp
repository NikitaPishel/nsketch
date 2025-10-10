#include <termios.h>
#include <cstdio>
#include <unistd.h>
#include <sys/select.h>
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

    bool IoKey::keyPressed() {
        timeval tv = {0, 0};
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        
        return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv) > 0;
    }

    int IoKey::getCharInt() {
        if (keyPressed()) {
            return std::getchar();
        }

        return '\0';
    }

    char IoKey::getChar() {
    return static_cast<char>(getCharInt());
    }
}