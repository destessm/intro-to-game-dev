// dynamic_array_tests.cpp
#include <iostream>
#include <gtest/gtest.h>
#include "dynamic_array.h"

class DynamicArrayTest : public testing::Test
{
  public:
    StevensDev::sgdc::DynamicArray<int> myArray;

    virtual void SetUp()
    {
        myArray.push( 80 );
        myArray.push( 4 );
    }

    virtual void TearDown()
    {
    }
};

TEST( DynamicArrayTest, LengthIsTwo )
{
    EXPECT_EQ( 2, myArray.getLength() );
}
