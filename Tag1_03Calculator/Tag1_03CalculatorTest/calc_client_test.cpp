#include "calc_client_test.h"
#include <exception>
using namespace testing;
TEST_F( calc_client_test , run)
{
	std::exception e{ "Upps" };

	EXPECT_CALL(calculator_mock, add(10.0, 20.0)).Times(1).WillOnce(Throw(e)); // Recordmode
	// Replay mode
	object_under_test.run();
}