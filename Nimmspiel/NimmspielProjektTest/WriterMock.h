#pragma once
#include <string>

#include "../Nimmspiel/writer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class WriterMock : public Writer
{
public:
	MOCK_METHOD(void, write, (std::string), (override));
};
