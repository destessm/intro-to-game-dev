#include <stdio.h>
#include <iostream>
#include <gtest/gtest.h>

TEST( sample_test_case, sample_test )
{
	EXPECT_EQ( 1, 1 );
}

int main(int argc, char **argv) 
{
	std::cout << "Hello World"<<"\n";
	::testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS();
}

