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
        status(true) {}
    
    void AppManager::Impl::checkStatus() {
        const std::string* currentKey = this->binds.autoGetBind();
        
        if (currentKey && *currentKey == "appStop") {
            std::cout << "exiting..." << std::endl;
            this->status = false;
        }
    }

    AppManager::AppManager () :
        pImpl(std::make_unique<Impl>()),
        tabs()
    {   
        this->tabs.emplace_back(std::make_unique<Tab>());
        this->interface.linkSketch(this->tabs[0]->sketch);
        this->interface.linkCursor(this->tabs[0]->cursor);
        this->interface.linkPalette(this->tabs[0]->colors);
    }
    
    AppManager::~AppManager() = default;

    Interface& AppManager::getInterface() {
        return this->interface;
    }
    
    void AppManager::runApp() {
        this->pImpl->binds.setBind('q', "appStop");
        this->interface.linkUiTex(this->uiTex);
        uiTex.linkApp(this);
        
        while (this->pImpl->status) {
            this->pImpl->checkStatus();
            this->interface.autoRunTool();

            this->uiTex.displayChanges();
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

}