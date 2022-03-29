#include "stapel_test.h"

TEST_F(stapel_test, is_empty_bla)
{
	EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(stapel_test, is_empty_blubb)
{
	object_under_test.push(1);
	EXPECT_FALSE(object_under_test.is_empty());
}