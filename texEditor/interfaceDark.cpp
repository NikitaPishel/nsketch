#include <iostream>
#include <chrono>
#include <string>
#include <ngph/texture.h>
#include <ngph/iotex.h>

using namespace std;
using namespace gph;

int main() {
    string path = "./data/textures/tex-base-dark.gph";
    
    // init interface texture table
    TexTable uiTexPack;
    uiTexPack.loadTable(path);

    // workspace background
    Texture workspBack = Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "white", "black")
        .build();

    // single pixel top menu
    Texture menuTopInner = Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "white", "black")
        .build();
        
    // top menu border
    Texture menuTopBorder = Texture::Builder(1, 1)
        .setPixel(0, 0, '-', "white", "black")
        .build();
    
    // single pixel tab
    Texture menuTopTabInner = Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "white", "black")
        .build();
    
    // top menu border
    Texture menuTopTabBorder = Texture::Builder(1, 1)
        .setPixel(0, 0, '|', "white", "black")
        .build();
    
    // single pixel down menu
    Texture menuDownInner = Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "white", "yellow")
        .build();
    
    // down menu border
    Texture menuDownBorder = Texture::Builder(1, 1)
        .setPixel(0, 0, '-', "white", "black")
        .build();
    
    // nSketch label on the bottom
    Texture menuDownLabel = Texture::Builder(7, 1)
        .setPixel(0, 0, 'n', "black", "yellow")
        .setPixel(1, 0, 'S', "black", "yellow")
        .setPixel(2, 0, 'k', "black", "yellow")
        .setPixel(3, 0, 'e', "black", "yellow")
        .setPixel(4, 0, 't', "black", "yellow")
        .setPixel(5, 0, 'c', "black", "yellow")
        .setPixel(6, 0, 'h', "black", "yellow")
        .build();
    
    // left menu border
    Texture menuLeftBorder = Texture::Builder(1, 1)
        .setPixel(0, 0, '|', "white", "black")
        .build();
    
    // left menu fill
    Texture menuLeftInner = Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "white", "black")
        .build();

    Texture cursorLeft = Texture::Builder(1, 1)
        .setPixel(0, 0, '>', "black", "bYellow")
        .build();

    Texture cursorRight = Texture::Builder(1, 1)
        .setPixel(0, 0, '<', "black", "bYellow")
        .build();
    
    uiTexPack.setTexture("workspace.background", workspBack);
    uiTexPack.setTexture("menuTop.inner", menuTopInner);
    uiTexPack.setTexture("menuTop.border", menuTopBorder);
    uiTexPack.setTexture("menuTop.tab.inner", menuTopTabInner);
    uiTexPack.setTexture("menuTop.tab.border", menuTopTabBorder);
    uiTexPack.setTexture("menuDown.inner", menuDownInner);
    uiTexPack.setTexture("menuDown.Border", menuDownBorder);
    uiTexPack.setTexture("menuDown.label", menuDownLabel);
    uiTexPack.setTexture("menuLeft.border", menuLeftBorder);
    uiTexPack.setTexture("menuLeft.inner", menuLeftInner);
    uiTexPack.setTexture("cursor.left", cursorLeft);
    uiTexPack.setTexture("cursor.right", cursorRight);

    uiTexPack.saveTable(path);
    
    return 0;
}