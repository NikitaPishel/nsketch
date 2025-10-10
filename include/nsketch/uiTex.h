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

        Texture::Builder barLeft;
        Texture::Builder barTop;
        Texture::Builder barBottom;
        Texture::Builder cursorPosLabel;
        Texture::Builder tabTemplate;

    public:
        void updateSketch();
        void updateCursor();
        void updatePalette();
    };
}

#endif