#pragma once
#include <iostream>
#include "calculator.h"
class calc_client
{
	calculator& calc;


public:
	calc_client(calculator& calc): calc(calc)
	{
	}

	void run()
	{
		double komplizierteForme1 = 10;
		double komplizierteForme2 = 20;
		std::cout << calc.add(komplizierteForme1, komplizierteForme2) << std::endl;
	}
};