#include <gtest/gtest.h>
#include "../includes/logic.h"

// Тесты для функции add
TEST(AddTest, Positive) { EXPECT_EQ(add(2, 2), 4); }
TEST(AddTest, Negative) { EXPECT_EQ(add(-1, -1), -2); }
TEST(AddTest, Zero) { EXPECT_EQ(add(0, 5), 5); }

// Тесты для функции multiply
TEST(MultTest, Positive) { EXPECT_EQ(multiply(3, 3), 9); }
TEST(MultTest, Negative) { EXPECT_EQ(multiply(-2, 3), -6); }
TEST(MultTest, Zero) { EXPECT_EQ(multiply(10, 0), 0); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
