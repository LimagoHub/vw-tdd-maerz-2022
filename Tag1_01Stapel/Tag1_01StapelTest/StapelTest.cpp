#include "StapelTest.h"

TEST_F(StapelTest, is_empty_leerer_stapel_returns_true)
{
	// Arrange

	

	// act + Assertion
	EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(StapelTest, is_empty_nicht_leerer_stapel_returns_false)
{
	// Arrange

	object_under_test.push(1);
	
	// Act
	bool ergebnis = object_under_test.is_empty();

	// Assertion
	EXPECT_FALSE(ergebnis);
}

TEST_F(StapelTest, is_empty_empty_again_returns_true)
{
	// Arrange

	object_under_test.push(1);
	object_under_test.pop();


	// Act
	bool ergebnis = object_under_test.is_empty();

	// Assertion
	EXPECT_TRUE(ergebnis);
}

TEST_F(StapelTest, push_fill_up_to_limit_no_exception_thrown)
{
	for (int i = 0; i < 9; i++)
		object_under_test.push(1);

	EXPECT_NO_THROW(object_under_test.push(1));
}

TEST_F(StapelTest, push_overflow_throws_stapelexception)
{
	for (int i = 0; i < 10; i++)
		object_under_test.push(1);

	EXPECT_THROW(object_under_test.push(1), StapelException);
}

TEST_F(StapelTest, push_overflow_throws_stapelexception_variante2)
{
	try
	{
		// Arrange
		for (int i = 0; i < 10; i++)
			object_under_test.push(i);
		// Act
		object_under_test.push(1);
		FAIL() << "expected exception is not thrown";
	}
	catch (StapelException& ex)
	{
		EXPECT_STREQ("Overflow", ex.what());
	}
}