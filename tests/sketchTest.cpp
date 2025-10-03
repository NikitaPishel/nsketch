#include <gtest/gtest.h>
#include <stdexcept>
#include"nsketch/sketch/sketch.h"
#include"nsketch/sketch/cursor.h"
#include"nsketch/sketch/palette.h"

using namespace nsk;

// test size getters
TEST(sketchTest, sketchSizeGetters) {
    Sketch sketch(4, 5);

    EXPECT_EQ(sketch.getXSize(), 4);
    EXPECT_EQ(sketch.getYSize(), 5);
}

// test resize method
TEST(sketchTest, sketchResize) {
    Sketch sketch(4, 5);

    EXPECT_NO_THROW(sketch.setSketchSize(3, 2));

    EXPECT_EQ(sketch.getXSize(), 3);
    EXPECT_EQ(sketch.getYSize(), 2);
}

// Check if range error handling works
TEST(sketchTest, setPixelRange) {
    Sketch sketch(5, 5);
    
    EXPECT_THROW(sketch.addPixel(0, -1, "white"), std::out_of_range);
    EXPECT_THROW(sketch.addPixel(-1, 0, "white"), std::out_of_range);
    EXPECT_THROW(sketch.addPixel(4, 5, "white"), std::out_of_range);
    EXPECT_THROW(sketch.addPixel(5, 4, "white"), std::out_of_range);

    EXPECT_NO_THROW(sketch.addPixel(0, 0, "white"));
    EXPECT_NO_THROW(sketch.addPixel(4, 4, "white"));
}


// Check if range error handling works
TEST(sketchTest, fillRange) {
    Sketch sketch(5, 5);
    
    EXPECT_THROW(sketch.fill(0, -1, 1, 1, "white"), std::out_of_range);
    EXPECT_THROW(sketch.fill(-1, 0, 1, 1, "white"), std::out_of_range);
    EXPECT_THROW(sketch.fill(4, 5, 1, 1, "white"), std::out_of_range);
    EXPECT_THROW(sketch.fill(5, 4, 1, 1, "white"), std::out_of_range);
    
    EXPECT_NO_THROW(sketch.fill(0, 0, 3, 3, "white"));
    EXPECT_NO_THROW(sketch.fill(4, 4, 3, 3, "white"));

}