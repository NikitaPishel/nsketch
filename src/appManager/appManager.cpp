#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "nsketch/appManager.h"
#include "appManagerImpl.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/tool/interface.h"
#include "nsketch/iokey.h"
#include "nsketch/uiTex.h"
#include "globalBinds.h"

using namespace gph;

namespace nsk {
    AppManager::Impl::Impl() :
        status(true),
        tabs(std::vector<Tab>(1))
    {
        interface.linkSketch(this->tabs[0].sketch);
        interface.linkCursor(this->tabs[0].cursor);
        interface.linkPalette(this->tabs[0].colors);
    }
    
    void AppManager::Impl::checkStatus() {
        const std::string* currentKey = this->binds.autoGetBind();
        
        if (currentKey && *currentKey == "appStop") {
            std::cout << "exiting..." << std::endl;
            this->status = false;
        }
    }

    AppManager::AppManager () : pImpl(std::make_unique<Impl>()) {}
    AppManager::~AppManager() = default;
    
    void AppManager::runApp() {
        this->pImpl->binds.setBind('q', "appStop");
        this->pImpl->interface.linkUiTex(this->pImpl->uiTex);
        
        while (this->pImpl->status) {
            this->pImpl->checkStatus();
            this->pImpl->interface.autoRunTool();
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}