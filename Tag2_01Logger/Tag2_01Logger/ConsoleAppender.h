#pragma once
#include "Appender.h"
#include <iostream>
class ConsoleAppender :
    public Appender
{
public:
	void write(std::string message) override
	{
		std::cout << message << std::endl;
	}
};

