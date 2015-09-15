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

    StevensDev::sgdc::DynamicArray<int>* myArray2 = new 
        StevensDev::sgdc::DynamicArray<int>(new 
            StevensDev::sgdm::CountingAllocator<int> );

    StevensDev::sgdc::DynamicArray<int>* myArray3 = new 
        StevensDev::sgdc::DynamicArray<int>(new 
            StevensDev::sgdm::CountingAllocator<int> );

    StevensDev::sgdc::DynamicArray<int>* myArray4 = new 
        StevensDev::sgdc::DynamicArray<int>(new 
            StevensDev::sgdm::CountingAllocator<int> );


    virtual void SetUp()
    {

        myArray->push( 80 );
        myArray->push( 4 );

        myArray1->push( 80 );
        myArray1->push( 2 );
        myArray1->popFront();
        myArray1->push( 5 );
        myArray1->push( 4 );
        myArray1->push( 100 );
        myArray1->push( 8 );
        myArray1->push( 3 );

        //myArray2=myArray;

        for( int i = 0; i < 12; i++ )
        {
            myArray2->pushFront( i );
        }

        for( int i = 0; i < 11; i++ )
        {
            myArray3->push( 2 );
        }
    }

    virtual void TearDown()
    {

        delete myArray;
        delete myArray1;
        delete myArray2;
        delete myArray3;
        delete myArray4;

        /*std::cout << "teardown: outstanding: " 
            << StevensDev::sgdm::CountingAllocator<int>::getTotalOutstandingCount()
            << "\n";*/
    }
};

TEST_F( DynamicArrayTest, LengthIsTwo )
{
    EXPECT_EQ( 2, myArray->getLength() );
}

TEST_F( DynamicArrayTest, PopReturnsAndShifts )
{
    EXPECT_EQ( 4, myArray->pop() );
    EXPECT_EQ( 1, myArray->getLength() );
}

TEST_F( DynamicArrayTest, AccessWithAt )
{
    EXPECT_EQ( 2, myArray1->at( 0 )  );
    std::cout << *myArray1 << "\n";
}


TEST_F( DynamicArrayTest, AssignmentOperator )
{
    EXPECT_EQ( 2, myArray4->getLength() );
    EXPECT_EQ( 80, myArray4->at( 0 ) );
}

TEST_F( DynamicArrayTest, PushFront )
{
    EXPECT_EQ( 11, myArray2->at( 0 ) );
}

TEST_F( DynamicArrayTest, PopFrontReturnsAndShifts )
{
    EXPECT_EQ( 11, myArray2->popFront() );
    EXPECT_EQ( 11, myArray2->getLength() );
    EXPECT_EQ( 10, myArray2->at( 0 ) );
}

TEST_F( DynamicArrayTest, RemoveAtAndInsertAt )
{
    EXPECT_EQ( 11, myArray3->getLength() );
    EXPECT_EQ( 2, myArray3->removeAt( 4 ) );
    EXPECT_EQ( 10, myArray3->getLength() );
    myArray3->insertAt( 99, 6 );
    EXPECT_EQ( 99, myArray3->at( 6 ) );
}

TEST_F( DynamicArrayTest, AllocatorConstructor )
{
    StevensDev::sgdm::CountingAllocator<int> myAlloc;
    int* myAllocated = myAlloc.get( 5 );
    StevensDev::sgdc::DynamicArray<int>* myArr = new 
        StevensDev::sgdc::DynamicArray<int>( &myAlloc );
    EXPECT_EQ( 10, myAlloc.getOutstandingCount() );
      // myAlloc has 5 outstanding from myAllocated and 5 from myArr
    myAlloc.release( myAllocated, 5 );
    delete myArr;
    EXPECT_EQ( 0, myAlloc.getOutstandingCount() );
}

/*
TEST_F( DynamicArrayTest, ArrayAssignmentOperator )
{
    //EXPECT_EQ( 10, myArray[0] );
}*/

TEST_F( DynamicArrayTest, MemoryLeakTest )
{
    EXPECT_EQ(50, StevensDev::sgdm::CountingAllocator<int>::getTotalOutstandingCount() );
}
