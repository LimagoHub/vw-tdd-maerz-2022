#pragma once
#include "DummyClassesForTest.h"
#include "../Nimmspiel/player.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"



class GamePlayerMock : public player<DummyBoard, DummyMove>
{
public:
	MOCK_METHOD(std::string, get_name, (), (const, override));
	MOCK_METHOD(DummyMove, do_move, (const DummyBoard& scene), (const, override));
};
