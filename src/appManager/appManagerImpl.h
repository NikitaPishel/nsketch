#ifndef APP_MANAGER_IMPL_H
#define APP_MANAGER_IMPL_H

#include <string>
#include <vector>
#include "nsketch/appManager.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/tool/interface.h"
#include "nsketch/iokey.h"
#include "nsketch/uiTex.h"
#include "globalBinds.h"

namespace nsk {
    class Tab {
    public:
        Sketch sketch;
        Cursor cursor;
        Palette colors;

        Tab(int xSize = 48, int ySize = 27) :
            sketch(xSize, ySize),
            cursor(),
            colors() {};
    };

    class AppManager::Impl {
    public:
        Impl();

        bool status;

        GlobalBinds binds;

        void checkStatus();
    };
}
#endif