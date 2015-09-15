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
    StevensDev::sgdm::CountingAllocator<int> myAlloc4;    

    int* myAllocated1;
    int* myAllocated2;
    int* myAllocated3;

    virtual void SetUp()
    {
        myAllocated1 = myAlloc1.get( 5 );

        myAllocated2 = myAlloc2.get( 5 );
        myAlloc2.release( myAllocated2, 5 );

        myAllocated3 = myAlloc3.get( 20 );
        myAlloc4 = myAlloc3;
    }

    virtual void TearDown()
    {
        myAlloc1.release( myAllocated1, 5 );
        myAlloc3.release( myAllocated3, 20 );
    }
};

TEST_F( CountingAllocatorTest, AllocationCount )
{
    EXPECT_EQ( 20, myAlloc3.getAllocationCount() );
    EXPECT_EQ( 5, myAlloc2.getAllocationCount() );
}

TEST_F( CountingAllocatorTest, ReleaseCount )
{
    EXPECT_EQ( 0, myAlloc3.getReleaseCount() );
    EXPECT_EQ( 5, myAlloc2.getReleaseCount() );
}

TEST_F( CountingAllocatorTest, OutstandingCount )
{
    EXPECT_EQ( 0, myAlloc.getOutstandingCount() );
    EXPECT_EQ( 5, myAlloc1.getOutstandingCount() );
    EXPECT_EQ( 0, myAlloc2.getOutstandingCount() );
} 

TEST_F( CountingAllocatorTest, TotalAllocationCount )
{
    EXPECT_EQ( 120, myAlloc.getTotalAllocationCount() );
      // expecting 120 because it adds up between passes
      // 5 + 5 + 20 = 30, 4 passes
      
} 

TEST_F( CountingAllocatorTest, TotalReleaseCount )
{
    EXPECT_EQ( 125, myAlloc.getTotalReleaseCount() );
      // expecting 125 because we release a total of 25
      // during each pass, and we have had 5 passes
} 

TEST_F( CountingAllocatorTest, TotalOutstandingCount )
{
    EXPECT_EQ( 25, myAlloc.getTotalOutstandingCount() );
      // expecting 25 because it hasn't called TearDown for this pass
      // 5 + 5 - 5 + 20 = 25
} 

TEST_F( CountingAllocatorTest, OstreamAndAssignmentOperatorTest )
{
    std::cout << myAlloc4 << "\n";
    EXPECT_EQ( 20, myAlloc4.getAllocationCount() );
}
