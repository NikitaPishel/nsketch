#include <memory>
#include <vector>
#include "nsketch/appManager.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/tool/interface.h"
#include "uiTex.h"

using namespace gph;

namespace nsk {
    class Tab {
    public:
        Sketch sketch;
        Cursor cursor;
        Palette colors;

        Tab(int xSize = 27, int ySize = 48) :
            sketch(xSize, ySize),
            cursor(),
            colors() {};
    };

    class AppManager::Impl {
    private:
        UiTex uiTex;

        Interface interface;

        

    public:
        Impl() {};

        void changeTab();
    };

    void AppManager::runApp() {

    }
}