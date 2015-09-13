// default_allocator_tests.cpp
#include <iostream>
#include <gtest/gtest.h>
#include "counting_allocator.h"

TEST( CountingAllocator, OutstandingCount )
{
    CountingAllocator <int> myAlloc ();
    EXPECT_EQ( 0, myAlloc.getOutstandingCount() );

    int *myAllocated = myAlloc.get( 5 );
    EXPECT_EQ( 5, myAlloc.getOutstandingCount() );

    myAlloc.release( myAllocated, 5 );\
    EXPECT_EQ( 0, myAlloc.getOutstandingCount() );
}

TEST( CountingAllocator, StaticCounts )
{
    CountingAllocator <int> myAlloc0();
    int *myAllocated0 = myAlloc0.get( 2 );
    CountingAllocator <int> myAlloc1();
    int *myAllocated1 = myAlloc1.get( 5 );
    EXPECT_EQ( 7, myAlloc1.getTotalOutstandingCount() );
}
