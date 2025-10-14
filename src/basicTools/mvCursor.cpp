#include <memory>
#include "nsketch/bTools/mvCursor.h"
#include "nsketch/tool/interface.h"
#include "nsketch/tool/tool.h"
#include "nsketch/tool/toolReg.h"
#include "nsketch/sketch/palette.h"
#include "nsketch/appManager.h"

namespace nsk {
    // ============ UP ============
    CursorMvUp::CursorMvUp() : Tool() {}
    
    void CursorMvUp::run() {
        Cursor& cursor = this->getCursor();
        Sketch& sketch = this->getSketch();
        UiCanv& ui = this->getUiCanv();
        
        if (cursor.getCursorY()+1 < sketch.getYSize()) {
            cursor.shiftCursor(0, 1);
        } 
        
        ui.updateCursor();
    }
    
    std::unique_ptr<Tool> CursorMvUp::clone() const {
        return std::make_unique<CursorMvUp>(*this);
    }
    
    static ToolReg mvUpReg("baseMvCursorUp", std::make_unique<CursorMvUp>());
    
    // ============ LEFT ============
    CursorMvLeft::CursorMvLeft() : Tool() {}
    
    void CursorMvLeft::run() {
        Cursor& cursor = this->getCursor();
        Sketch& sketch = this->getSketch();
        UiCanv& ui = this->getUiCanv();
        
        if (cursor.getCursorX()-1 >= 0) {
            cursor.shiftCursor(-1, 0);
        } 
        
        ui.updateCursor();
    }
    
    std::unique_ptr<Tool> CursorMvLeft::clone() const {
        return std::make_unique<CursorMvLeft>(*this);
    }
    
    static ToolReg mvLeftReg("baseMvCursorLeft", std::make_unique<CursorMvLeft>());
    
    // ============ DOWN ============
    CursorMvDown::CursorMvDown() : Tool() {}
    
    void CursorMvDown::run() {
        Cursor& cursor = this->getCursor();
        Sketch& sketch = this->getSketch();
        UiCanv& ui = this->getUiCanv();
        
        if (cursor.getCursorY()-1 >= 0) {
            cursor.shiftCursor(0, -1);
        } 
        
        ui.updateCursor();
    }
    
    std::unique_ptr<Tool> CursorMvDown::clone() const {
        return std::make_unique<CursorMvDown>(*this);
    }
    
    static ToolReg mvDownReg("baseMvCursorDown", std::make_unique<CursorMvDown>());
    
    // ============ RIGHT ============
    CursorMvRight::CursorMvRight() : Tool() {}

    void CursorMvRight::run() {
        Cursor& cursor = this->getCursor();
        Sketch& sketch = this->getSketch();
        UiCanv& ui = this->getUiCanv();
        
        if (cursor.getCursorX()+1 < sketch.getXSize()) {
            cursor.shiftCursor(1, 0);
        } 
        
        ui.updateCursor();
    }

    std::unique_ptr<Tool> CursorMvRight::clone() const {
        return std::make_unique<CursorMvRight>(*this);
    }

    static ToolReg mvRightReg("baseMvCursorRight", std::make_unique<CursorMvRight>());
}