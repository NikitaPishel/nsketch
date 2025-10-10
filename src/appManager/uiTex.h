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

    public:
        
        void updateUi();
    };
}

#endif