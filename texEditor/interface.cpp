#include <iostream>
#include <chrono>
#include <string>
#include <ngph/texture.h>
#include <ngph/iotex.h>

using namespace std;
using namespace gph;

int main() {
    string path = "./data/textures/uiTexPack.gph";
    
    // init interface texture table
    TexTable uiTexPack;
    uiTexPack.loadTable(path);

    // workspace background
    Texture workspBack = Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "white", "black")
        .build();

    uiTexPack.setTexture("workspaceBackground", workspBack);

    // single pixel down menu
    Texture menuDown = Texture::Builder(1, 1)
        .fillTexture(' ', "black", "yellow")
        .build();

    uiTexPack.setTexture("menuDown", menuDown);
    
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
    
    uiTexPack.setTexture("menuDownLabel", menuDownLabel);
    
    // left menu border
    Texture menuLeftBorder = Texture::Builder(1, 2)
        .setPixel(0, 0, ' ', "white", "green")
        .setPixel(0, 1, ' ', "white", "grey")
        .build();

    uiTexPack.setTexture("menuLeftBorder", menuLeftBorder);
    
    // left menu fill
    Texture menuLeftFill = Texture::Builder(1, 1)
    .setPixel(0, 0, ' ', "white", "yellow")
    .build();

    uiTexPack.setTexture("menuLeftFill", menuLeftFill);

    uiTexPack.saveTable(path);
    
    return 0;
}