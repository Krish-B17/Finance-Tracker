#include <gtest/gtest.h>

// main function, entry point for all test cases
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
