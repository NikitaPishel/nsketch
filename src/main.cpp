#include <iostream>
#include <chrono>
#include <ngph/canvas.h>
#include <ngph/texture.h>
#include <ngph/iotex.h>

using namespace std;
using namespace gph;

int main() {
    Canvas canv(32, 12);
    canv.updateSize();

    const uint32_t& xSize = canv.getXSize();
    const uint32_t& ySize = canv.getYSize();

    TexTable uiPack;
    uiPack.loadTable("./data/textures/uiTexPack.gph");

    canv.fillWithTexture(uiPack.getTexture("workspaceBackground"));
    
    canv.iterateTexture(0, ySize-1, xSize, 1, uiPack.getTexture("menuDown"));
    canv.addTexture(xSize-10, ySize-1, uiPack.getTexture("menuDownLabel"));
    
    canv.iterateTexture(0, 0, 15, ySize+1, uiPack.getTexture("menuLeftFill"));
    canv.iterateTexture(15, 0, 1, ySize/2+1, uiPack.getTexture("menuLeftBorder"));

    canv.render();
    
    return 0;
}