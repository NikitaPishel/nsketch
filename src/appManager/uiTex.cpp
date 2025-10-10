#include "nsketch/uiTex.h"
#include "nsketch/appManager.h"

namespace nsk {
    UiTex::UiTex() :
        modified(true),
        appPtr(nullptr)
    {
        // delete this part when switching to tex table
        this->barLeft
            .setSize(3, 1)
            .fillTexture(' ')
            .setPixel(2, 0, '|');

        this->barTop
            .setSize(1, 2)
            .setPixel(0, 0, ' ')
            .setPixel(0, 1, '-');
    }

    void UiTex::linkApp(AppManager* appPtr) {
        this->appPtr = appPtr;

        this->canvas.updateSize();
        this->updateSketch();
        this->updatePalette();
        this->updateCursor();
    }
    
    void UiTex::autoScale() {
        bool resized = this->canvas.updateSize();

        if (resized) {
            updateCanvResize();
        }
    }
    
    void UiTex::updateCanvResize() {
        this->modified = true;

        const int& width = this->canvas.getXSize();
        const int& height = this->canvas.getYSize();

        int tabTempSize = width / 5;

        if (tabTempSize < 7) {
            tabTempSize = 7;
        }

        this->tabTemplate.setSize(tabTempSize, 1);
        tabTemplate.setPixel(0, 0, '|');
        tabTemplate.setPixel(tabTempSize-1, 0, '|');
    }
    
    void UiTex::updateSketch() {
        this->modified = true;

        Interface& interface = this->appPtr->getInterface();
        
        canvas.addTexture(3, 2, interface.getSketch().texturize());
    };
    
    void UiTex::updateCursor() {
        this->modified = true;
        
    };
    
    void UiTex::updatePalette() {
        this->modified = true;
        
    };

    void UiTex::displayChanges() {
        if (modified) {
            //int tabsNum = this->appPtr->tabs.size();
            //this->canvas.iterateTexture(0, 1, 1, canvas.getXSize(), this->barTop.build());
            //this->canvas.iterateTexture(0, 0, tabsNum, 1, this->tabTemplate.build());

            //int barLeftHeight = this->canvas.getYSize() - 3;
            //this->canvas.iterateTexture(0, 2, 1, barLeftHeight, this->barLeft.build());
        }
    }
}