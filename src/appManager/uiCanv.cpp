#include <iostream>
#include "nsketch/uiCanv.h"
#include "nsketch/appManager.h"

namespace nsk {
    UiCanv::UiCanv() :
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

    void UiCanv::linkApp(AppManager* appPtr) {
        this->appPtr = appPtr;

        this->canvas.updateSize();
        this->updateSketch();
        this->updatePalette();
        this->updateCursor();
    }
    
    void UiCanv::autoScale() {
        bool resized = this->canvas.updateSize();

        if (resized) {
            updateCanvResize();

            std::cout << "\033[J\033[H" << std::flush;
            this->canvas.render();
        }
    }
    
    void UiCanv::updateCanvResize() {
        this->modified = true;

        const int& width = this->canvas.getXSize();
        const int& height = this->canvas.getYSize();
        
        int tabTempSize = width / 5;
        
        if (tabTempSize < 7) {
            tabTempSize = 7;
        }
        
        this->tabTemplate.setSize(tabTempSize, 1);
        tabTemplate.fillTexture(' ');
        tabTemplate.setPixel(0, 0, '|');
        tabTemplate.setPixel(tabTempSize-1, 0, '|');

        Texture black = Texture::Builder(1, 1).fillTexture(' ', "white", "black").build();

        updateSketch();
        updateCursor();
        updatePalette();
    }
    
    void UiCanv::updateSketch() {
        this->modified = true;

        Interface& interface = this->appPtr->getInterface();
        
        canvas.addTexture(3, 2, interface.getSketch().texturize());
    };
    
    void UiCanv::updateCursor() {
        this->modified = true;
        
    };
    
    void UiCanv::updatePalette() {
        this->modified = true;
        
    };

    void UiCanv::displayChanges() {
        if (modified) {
            int tabsNum = this->appPtr->tabs.size();
            this->canvas.iterateTexture(0, 0, canvas.getXSize(), 1, this->barTop.create());
            this->canvas.iterateTexture(0, 0, tabsNum, 1, this->tabTemplate.create());

            int barLeftHeight = this->canvas.getYSize() - 3;
            this->canvas.iterateTexture(0, 2, 1, barLeftHeight, this->barLeft.create());

            this->canvas.render();
        }
    }
}