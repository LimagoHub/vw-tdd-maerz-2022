#pragma once
#include "calculator.h"
class calculator_impl: public calculator
{
public:
	double add(double a, double b) override
	{
		return a + b;
	}
	double sub(double a, double b) override
	{
		return add(a,-b);
	}
};
