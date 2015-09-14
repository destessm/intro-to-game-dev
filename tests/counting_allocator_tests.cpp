// counting_allocator_tests.cpp
#include <iostream>
#include <gtest/gtest.h>
#include "counting_allocator.h"

class CountingAllocatorTest : public testing::Test
{
  public:
    StevensDev::sgdm::CountingAllocator<int> myAlloc;
    StevensDev::sgdm::CountingAllocator<int> myAlloc1;
    StevensDev::sgdm::CountingAllocator<int> myAlloc2;

    virtual void SetUp()
    {
        int *myAllocated1 = myAlloc1.get( 5 );

        int *myAllocated2 = myAlloc2.get( 5 );
        myAlloc1.release( myAllocated1, 5 );
    }

    virtual void TearDown()
    {
    }
}

TEST( CountingAllocatorTest, OutstandingCountZeroStart )
{
    EXPECT_EQ( 0, myAlloc.getOutstandingCount() );
}

TEST( CountingAllocatorTest, OutstandingCountFive )
{
    EXPECT_EQ( 5, myAlloc1.getOutstandingCount() );
}

Test( CountingAllocatorTest, OutstandingCountZeroEnd )
{
    EXPECT_EQ( 0, myAlloc2.getOutstandingCount() );
}

TEST( CountingAllocatorTest, StaticCounts )
{
    StevensDev::sgdm::CountingAllocator <int> myAlloc0;
    int *myAllocated0 = myAlloc0.get( 2 );

    StevensDev::sgdm::CountingAllocator <int> myAlloc1;
    int *myAllocated1 = myAlloc1.get( 5 );

    EXPECT_EQ( 7, myAlloc0.getTotalOutstandingCount() );
}
