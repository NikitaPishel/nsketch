#include <iostream>
#include "nsketch/uiCanv.h"
#include "nsketch/appManager.h"
#include "nsketch/sketch/cursor.h"
#include "uiTex.h"
#include "nsketch/iokey.h"

namespace nsk {
    UiCanv::UiCanv() :
        uiTexPtr(std::make_unique<UiTex>("./data/textures/tex-base-dark.gph")),
        appPtr(nullptr) {}

    UiCanv::~UiCanv() {}
    
    void UiCanv::linkApp(AppManager* appPtr) {
        this->appPtr = appPtr;

        this->canvas.updateSize();
        this->updateCanvResize();
        
        this->updateSketch();
        this->updatePalette();
        this->updateCursor();
    }
    
    void UiCanv::autoScale() {
        bool resized = this->canvas.updateSize();

        if (resized) {
            updateCanvResize();
        }
    }
    
    void UiCanv::updateCanvResize() {
        const int& width = this->canvas.getXSize();
        const int& height = this->canvas.getYSize();
        
        int newTabSize = width / 5;
        
        if (newTabSize < 7) {
            newTabSize = 7;
        }
        
        if (newTabSize != uiTexPtr->menuTopTab.getXSize())
        uiTexPtr->menuTopTab
            .setSize(newTabSize, 1)
            .fillWithTexture(uiTexPtr->menuTopTabInner)
            .addTexture(0, 0, uiTexPtr->menuTopTabBorder)
            .addTexture(newTabSize-1, 0, uiTexPtr->menuTopTabBorder);

        this->updateSketch();
        this->updateCursor();
        this->updatePalette();

        uiTexPtr->modMenuTop = true;
    }
    
    void UiCanv::updateSketch() {
        uiTexPtr->modSketch = true;
        
        Interface& interface = this->appPtr->getInterface();
    };
    
    void UiCanv::updateCursor() {
        uiTexPtr->modSketch = true;
        uiTexPtr->modMenuLeft = true;
    };
    
    void UiCanv::updatePalette() {
        uiTexPtr->modMenuLeft = true;
    };

    void UiCanv::displayChanges() {
        bool modified = false;
        Interface& interface = this->appPtr->getInterface();
        Cursor& cursor = interface.getCursor();

        if (uiTexPtr->modSketch) {
            modified = true;
            uiTexPtr->modMenuBot = true;
            uiTexPtr->modSketch = false;

            int canvXShift = 3;
            int canvYShift = 2;
            
            this->canvas.iterateTexture(3, 2, canvas.getXSize()-3, canvas.getYSize()-4, uiTexPtr->workspBackground);
            canvas.addTexture(canvXShift, canvYShift, interface.getSketch().texturize());

            int cursorLeftXPos = cursor.getCursorX()*2 - 1 + canvXShift;
            int cursorRightXPos = cursor.getCursorX()*2 + 2 + canvXShift;

            int cursorYPos = cursor.getCursorY() + canvYShift;

            if (cursorYPos < this->canvas.getYSize()) {
                if (cursorLeftXPos >= 0 && cursorLeftXPos < this->canvas.getXSize()) {
                    this->canvas.addTexture(cursorLeftXPos, cursorYPos, uiTexPtr->cursorLeft);
                }

                if (cursor.getCursorX() < interface.getSketch().getXSize() && cursorRightXPos < this->canvas.getXSize()) {
                    this->canvas.addTexture(cursorRightXPos, cursorYPos, uiTexPtr->cursorRight);
                }
            }
        }

        if (uiTexPtr->modMenuTop) {
            modified = true;
            uiTexPtr->modMenuTop = false;

            int tabsNum = this->appPtr->tabs.size();
            this->canvas.iterateTexture(0, 0, canvas.getXSize(), 1, uiTexPtr->menuTopInner);
            this->canvas.iterateTexture(0, 1, canvas.getXSize(), 1, uiTexPtr->menuTopBorder);
            
            this->canvas.iterateTexture(0, 0, tabsNum, 1, uiTexPtr->menuTopTab.create());
        }

        if (uiTexPtr->modMenuLeft) {
            modified = true;
            uiTexPtr->modMenuLeft = false;
            
            this->canvas.iterateTexture(0, 2, 2, canvas.getYSize()-4, uiTexPtr->menuLeftInner);
            this->canvas.iterateTexture(2, 2, 1, canvas.getYSize()-4, uiTexPtr->menuLeftBorder);
        }

        if (uiTexPtr->modMenuBot) {
            modified = true;
            uiTexPtr->modMenuBot = false;
            
            this->canvas.iterateTexture(0, canvas.getYSize()-2, canvas.getXSize(), 1, this->uiTexPtr->menuDownBorder);
            this->canvas.iterateTexture(0, canvas.getYSize()-1, canvas.getXSize(), 1, this->uiTexPtr->menuDownInner);

            int labelPos = canvas.getXSize() - uiTexPtr->menuDownLabel.getXSize();
            
            this->canvas.iterateTexture(labelPos-3, canvas.getYSize()-1, 1, 1, this->uiTexPtr->menuDownLabel);
        }

        if (modified) {
            this->canvas.render();
        }

    }
}