#ifndef UI_TEXTURIZER_H
#define UI_TEXTURIZER_H

#include <ngph/canvas.h>
#include <ngph/texture.h>

using namespace gph;

namespace nsk {
    class AppManager;
    
    class UiTex {
    private:
        AppManager* appPtr;
        Canvas canvas;
        bool modified;

        // later replace with a tex table
        Texture::Builder barLeft;
        Texture::Builder barTop;
        Texture::Builder barBottom;
        Texture::Builder barBottomText;
        Texture::Builder cursorPosLabel;
        Texture::Builder tabTemplate;

        void drawBarLeft();
        void drawBarTop();
        void updateCanvResize();

    public:
        UiTex();
        void linkApp(AppManager* appPtr);
    
        void autoScale();
        void updateSketch();
        void updateCursor();
        void updatePalette();
        
        void displayChanges();
    };
}

#endif