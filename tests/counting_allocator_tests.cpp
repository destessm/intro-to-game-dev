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
    StevensDev::sgdm::CountingAllocator<int> myAlloc3;

    virtual void SetUp()
    {
        int *myAllocated1 = myAlloc1.get( 5 );

        int *myAllocated2 = myAlloc2.get( 5 );
        myAlloc2.release( myAllocated2, 5 );

        int *myAllocated3 = myAlloc3.get( 20 );
    }

    virtual void TearDown()
    {
    }
};

TEST_F( CountingAllocatorTest, OutstandingCountZeroStart )
{
    EXPECT_EQ( 0, myAlloc.getOutstandingCount() );
} // passed

TEST_F( CountingAllocatorTest, OutstandingCountFive )
{
    EXPECT_EQ( 5, myAlloc1.getOutstandingCount() );
} // passed

TEST_F( CountingAllocatorTest, OutstandingCountZeroEnd )
{
    EXPECT_EQ( 0, myAlloc2.getOutstandingCount() );
} // passed

TEST_F( CountingAllocatorTest, StaticCounts )
{
    EXPECT_EQ( 100, myAlloc.getTotalOutstandingCount() );
      // expecting 100 because it runs the set up for each of the four tests, 
      // and the static count remains between them. Each time it counts 25.
} 
