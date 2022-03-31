#pragma once
#include <string>

#include "../Nimmspiel/Writer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class Mockwriter : public Writer
{
public:
	MOCK_METHOD(void, write, (std::string), (override));
};