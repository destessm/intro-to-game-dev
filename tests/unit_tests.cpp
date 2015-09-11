#include <iostream>
#include <gtest/gtest.h>

TEST( TrivialTest1, ExpectEquals )
{
    EXPECT_EQ( 1, 1 );
    EXPECT_EQ( 2 + 9, 11 );
}

TEST( TrivialTest2, AssertTrue )
{
    ASSERT_TRUE( 1 == 1 );
    ASSERT_TRUE( true );
}

TEST( TrivialTest3, ExpectLessThan )
{
    EXPECT_LT( 10, 5000 );
    EXPECT_LT( -30, 0 );
}
