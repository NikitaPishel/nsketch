#ifndef APP_MANAGER_MAIN_H
#define APP_MANAGER_H

#include <memory>

namespace nsk {
    class AppManager {
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        AppManager();

        void runApp();
    };
}

#endif