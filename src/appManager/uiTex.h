#ifndef APP_TEXTURE_MANAGER_H
#define APP_TEXTURE_MANAGER_H

#include <string>
#include <ngph/iotex.h>

using namespace gph;

namespace nsk {
    class UiTex {
    private:
        TexTable texPack;
    
    public:
        UiTex(const std::string& path);

        Texture workspBackground;
        Texture menuTopInner;
        Texture menuTopBorder;
        Texture menuTopTabInner;
        Texture menuTopTabBorder;
        Texture menuDownInner;
        Texture menuDownBorder;
        Texture menuDownLabel;
        Texture menuLeftInner;
        Texture menuLeftBorder;

        Texture::Builder menuTopTab;

        bool modSketch;
        bool modMenuTop;
        bool modMenuLeft;
        bool modMenuBot;
    };
}

#endif