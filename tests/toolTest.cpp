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

    EXPECT_NO_THROW(interface.addTool('b', std::move(myPencil)));
}

TEST(toolTest, testInterfaceIo) {
    Interface interface;

    EmptyTool tool;
    
    EXPECT_NO_THROW(interface.addTool('e', std::make_unique<EmptyTool>(tool)));
    EXPECT_NO_THROW(interface.getTool('e'));
    EXPECT_NO_THROW(interface.delTool('e'));
    EXPECT_THROW(interface.getTool('e'), std::runtime_error);
    EXPECT_NO_THROW(interface.addToolFromStore('b', "basePencil"));
}