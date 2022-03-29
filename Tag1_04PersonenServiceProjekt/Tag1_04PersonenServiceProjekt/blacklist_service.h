#pragma once

#include <string>
class blacklist_service
{
public:
	virtual bool is_allowed(std::string vorname)=0;
};