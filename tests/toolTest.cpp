#include <gtest/gtest.h>
#include <memory>
#include <tool/tool.h>
#include <tool/toolStore.h>
#include <tool/toolReg.h>
#include <tool/interface.h>
#include <bTools/pencil.h>

using namespace nsk;

// test if tool store works
TEST(toolTest, getToolFromStore) {
    ToolStore store = ToolStore::getInstance();
    EXPECT_NO_THROW(std::unique_ptr<Tool> myPencil = store.createTool("basePencil"));
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
    ToolStore store = ToolStore::getInstance();
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