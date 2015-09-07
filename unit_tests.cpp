#include <iostream>
#include <gtest/gtest.h>

TEST( UnitTest1, ExpectEquals )
{
    EXPECT_EQ( 1, 1 );
    EXPECT_EQ( 2 + 9, 11 );
}

TEST( UnitTest2, AssertTrue )
{
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(true);
}
