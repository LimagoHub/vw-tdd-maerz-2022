#pragma once

#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {

	// Arrange
	// Act (ion)

	// Assertion
	ASSERT_EQ(1, 1); // Sofortiges Ende des Test -> gescheitert
  EXPECT_EQ(1, 1); // test läuft weiter -> gescheitert
  EXPECT_TRUE(true);
}