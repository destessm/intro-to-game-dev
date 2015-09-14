// main_tests.cpp
#include <iostream>
#include <gtest/gtest.h>
#include "counting_allocator_tests.cpp"
#include "dynamic_array_tests.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
