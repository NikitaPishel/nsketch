#include <gtest/gtest.h>
#include <memory>
#include "nsketch/tool/tool.h"
#include "nsketch/tool/toolStore.h"
#include "nsketch/tool/toolReg.h"
#include "nsketch/tool/interface.h"
#include "nsketch/bTools/pencil.h"

using namespace nsk;

static ToolReg pencilReg("basePencil", std::make_unique<Pencil>());

// test if tool store works
TEST(toolTest, getToolFromStore) {
    ToolStore& store = ToolStore::getInstance();
    //EXPECT_NO_THROW(std::unique_ptr<Tool> myPencil = store.createTool("basePencil"));
}

TEST(toolTest, addToolToInterface) {
    Sketch sketch;
    Cursor cursor;
    Palette palette;

    Interface interface;

    interface.linkSketch(sketch);
    interface.linkCursor(cursor);
    interface.linkPalette(palette);

    EXPECT_EQ(&interface.getSketch(), &sketch);
    EXPECT_EQ(&interface.getCursor(), &cursor);
    EXPECT_EQ(&interface.getPalette(), &palette);
}

TEST(toolTest, useToolFromInterface) {
    ToolStore& store = ToolStore::getInstance();
    std::unique_ptr<Tool> myPencil = store.createTool("basePencil");
    
    Sketch sketch;
    Cursor cursor;
    Palette palette;

    Interface interface;

    interface.linkSketch(sketch);
    interface.linkCursor(cursor);
    interface.linkPalette(palette);

    EXPECT_NO_THROW(interface.setTool("pencil", std::move(myPencil)));
}

TEST(toolTest, caseOne) {

}