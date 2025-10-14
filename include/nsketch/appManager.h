#ifndef APP_MANAGER_MAIN_H
#define APP_MANAGER_MAIN_H

#include <memory>
#include "nsketch/tool/interface.h"
#include "uiCanv.h"

namespace nsk {
    class Tab;

    class AppManager {
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

        Interface interface;
        
        public:
        AppManager();
        ~AppManager();
        
        std::vector<std::unique_ptr<Tab>> tabs;
        Interface& getInterface();
        UiCanv uiCanv;

        void runApp();
    };
}

#endif