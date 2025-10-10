#include <memory>
#include <thread>
#include <chrono>
#include "nsketch/appManager.h"
#include "appManagerImpl.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/tool/interface.h"
#include "nsketch/iokey.h"
#include "uiTex.h"
#include "globalBinds.h"

using namespace gph;

namespace nsk {
    AppManager::Impl::Impl() : status(true) {}
    
    void AppManager::Impl::checkStatus() {
        const std::string* currentKey = this->binds.autoGetBind();
        
        if (currentKey && *currentKey == "appStop") {
            this->status = false;
        }
    }

    AppManager::AppManager () : pImpl(std::make_unique<Impl>()) {}
    AppManager::~AppManager() = default;
    
    void AppManager::runApp() {
        this->pImpl->binds.setBind('q', "appStop");
        
        while (this->pImpl->status) {
            this->pImpl->checkStatus();
            this->pImpl->interface.autoRunTool();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}