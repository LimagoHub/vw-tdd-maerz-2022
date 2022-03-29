#pragma once
#include <iostream>
#include <string>
#include "Appender.h"
class Logger
{

	Appender& appender;
public:

	Logger(Appender& appender)
		: appender(appender)
	{
	}

	void log(std::string message)
	{
		const std::string prefix = "PREFIX: ";
		appender.write( prefix + message);
	}
};

