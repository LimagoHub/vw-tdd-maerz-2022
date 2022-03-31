#pragma once
#include "../Nimmspiel/AbstractGame.h"
#include "DummyClassesForTest.h"
#include "../Nimmspiel/writer.h"
class MyAbstractGameDummy: public AbstractGame<DummyBoard, DummyMove>
{
public:
	bool game_over{ false };
	bool valid{ true };
	
	MyAbstractGameDummy(Writer& w)
		: AbstractGame<DummyBoard, DummyMove>(w)
	{
	}


public:
	bool is_gameover() const override { return game_over; }
	bool is_valid() const override { return valid; }
	void update_game_state() override {}
};

