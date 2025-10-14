#include "uiTex.h"

namespace nsk {
    UiTex::UiTex(const std::string& path) :
        modSketch(true),
        modMenuTop(true),
        modMenuLeft(true),
        modMenuBot(true) 
    {
        this->texPack.loadTable(path);

        this->workspBackground = this->texPack.getTextureRef("workspace.background");
        this->menuTopInner = this->texPack.getTextureRef("menuTop.inner");
        this->menuTopBorder = this->texPack.getTextureRef("menuTop.border");
        this->menuTopTabInner = this->texPack.getTextureRef("menuTop.tab.inner");
        this->menuTopTabBorder = this->texPack.getTextureRef("menuTop.tab.border");
        this->menuDownInner = this->texPack.getTextureRef("menuDown.inner");
        this->menuDownBorder = this->texPack.getTextureRef("menuDown.Border");
        this->menuDownLabel = this->texPack.getTextureRef("menuDown.label");
        this->menuLeftInner = this->texPack.getTextureRef("menuLeft.border");
        this->menuLeftBorder = this->texPack.getTextureRef("menuLeft.inner");
    }
}