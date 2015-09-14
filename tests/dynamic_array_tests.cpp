// dynamic_array_tests.cpp
#include <iostream>
#include <gtest/gtest.h>
#include "dynamic_array.h"

class DynamicArrayTest : public testing::Test
{
  public:
    StevensDev::sgdc::DynamicArray<int>* myArray = new 
        StevensDev::sgdc::DynamicArray<int>(new 
            StevensDev::sgdm::CountingAllocator<int> );

    StevensDev::sgdc::DynamicArray<int>* myArray1 = new 
        StevensDev::sgdc::DynamicArray<int>(new 
            StevensDev::sgdm::CountingAllocator<int> );

    virtual void SetUp()
    {
        myArray->push( 80 );
        myArray->push( 4 );

        myArray1->push( 80 );
        myArray1->push( 2 );
        myArray1->popFront();
    }

    virtual void TearDown()
    {
    }
};

TEST_F( DynamicArrayTest, LengthIsTwo )
{
    EXPECT_EQ( 2, myArray->getLength() );
}

TEST_F( DynamicArrayTest, PopIsFour )
{
    EXPECT_EQ( 4, myArray->pop() );
}

TEST_F( DynamicArrayTest, AccessZeroIndexIsTwo )
{
    EXPECT_EQ( 2, myArray1->at( 0 )  );
}
