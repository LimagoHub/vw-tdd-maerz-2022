#include "AbstractGameTest.h"

TEST_F(AbstractGameTest, play_success)
{


	EXPECT_CALL(game_player_mock, do_move(_)).WillOnce([this](DummyBoard d)
		{
			object_under_test.game_over = true;
			return DummyMove{};
		});

	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren.\n")));

	object_under_test.play();
}

TEST_F(AbstractGameTest, play_mogeln)
{

	object_under_test.valid = false;

	EXPECT_CALL(game_player_mock, do_move(_)).WillRepeatedly([this](DummyBoard d)
		{
			object_under_test.game_over = true;
			return DummyMove{};
		});

	EXPECT_CALL(writer_mock, write(Eq("ungueltiger Zug \n"))).WillOnce([this](std::string s) { object_under_test.valid = true; });
	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren.\n")));

	object_under_test.play();
}
