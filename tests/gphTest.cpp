#include <gtest/gtest.h>
#include "graphics/grid.h"

using namespace gph;

// unnamed namespace – limits access to tests
namespace {

// Test grid creation with zero size
TEST(gridTest, ZeroGrid) {
    EXPECT_THROW({ Grid grid(0, 1); }, std::exception);
    EXPECT_THROW({ Grid grid(1, 0); }, std::exception);
    EXPECT_THROW({ Grid grid(0, 0); }, std::exception);
}

// Test grid creation with negatives
TEST(gridTest, NegGrid) {
    EXPECT_THROW({ Grid grid(2, -2); }, std::exception);
    EXPECT_THROW({ Grid grid(-2, 2); }, std::exception);
    EXPECT_THROW({ Grid grid(-2, -2); }, std::exception);
}

// Test accessing valid default pixel
TEST(gridTest, CheckGetElmnt) {
    Grid grid(3, 2);
    EXPECT_EQ(grid.getPixel(0, 0).symbol, ' ');
    EXPECT_NO_THROW(grid.getPixel(2, 1));
}

// Test grid dimension values directly
TEST(gridTest, CheckDimensions) {
    Grid grid(3, 2);
    EXPECT_EQ(grid.xSize, 3);
    EXPECT_EQ(grid.ySize, 2);
}

// Test adding and retrieving pixel
TEST(gridTest, CheckAddPixel) {
    Grid grid(4, 3);
    Grid::Pixel pix;
    pix.symbol = '1';
    pix.textColor = 2;
    pix.backColor = 3;

    grid.addPixel(3, 2, pix);
    Grid::Pixel retrieved = grid.getPixel(3, 2);

    EXPECT_EQ(retrieved.symbol, '1');
    EXPECT_EQ(retrieved.textColor, 2);
    EXPECT_EQ(retrieved.backColor, 3);
}

// Test accessing pixel out of bounds
TEST(gridTest, OutOfRange) {
    Grid grid(3, 2);
    EXPECT_THROW(grid.getPixel(3, 1), std::out_of_range);
    EXPECT_THROW(grid.getPixel(0, 2), std::out_of_range);
    EXPECT_THROW(grid.getPixel(-1, 0), std::out_of_range);
    EXPECT_THROW(grid.getPixel(0, -1), std::out_of_range);
}

}