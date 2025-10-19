#ifndef UI_TEXTURIZER_H
#define UI_TEXTURIZER_H

#include <memory>
#include <ngph/canvas.h>
#include <ngph/texture.h>

using namespace gph;

namespace nsk {
    class UiTex;
    class AppManager;
    
    class UiCanv {
    private:
        AppManager* appPtr;
        
        std::unique_ptr<UiTex> uiTexPtr;

        void drawBarLeft();
        void drawBarTop();
        void updateCanvResize();
        
    public:
        Canvas canvas;
        UiCanv();
        ~UiCanv();
        void linkApp(AppManager* appPtr);
    
        void autoScale();
        void updateSketch();
        void updateCursor();
        void updatePalette();
        
        void displayChanges();
    };
}

#endif