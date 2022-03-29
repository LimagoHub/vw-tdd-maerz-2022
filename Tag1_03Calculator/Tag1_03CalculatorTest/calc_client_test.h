#pragma once
#include "gtest/gtest.h"
#include "../Tag1_03Calculator/CalcClient.h"
#include "Mockcalculator.h"

class calc_client_test:public testing::Test
{
protected:
	Mockcalculator calculator_mock;
	calc_client object_under_test{ calculator_mock };



	
};
