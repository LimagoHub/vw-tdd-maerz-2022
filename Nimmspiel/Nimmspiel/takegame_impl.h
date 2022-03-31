#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "game.h"
class takegame_impl: public game
{
	
	int stones;
	int move;

	bool is_gameover() const
	{
		return stones < 1;
	}

	void do_moves()
	{
		spielerzug();
		computerzug();
	}

	void computerzug()
	{
		if (is_gameover()) return;
		
		std::vector<int> moves{ 3,1,1,2 };
		
		
		move = moves[stones % 4];
		print("Computer nimmt " + std::to_string(move) + " Steine.");
		terminate_move("Computer");
	}

	

	void spielerzug()
	{
		if (is_gameover()) return;
		execute_move();
		terminate_move("Spieler");
		
	}

	void execute_move()
	{
		do
		{
			players_move();
		} while (move_is_not_valid());
		
		
	}

	void players_move()
	{
		print("Es gibt " + std::to_string(stones) + " Steine. Bitte nehmen Sie 1,2 oder 3!");
		std::cin >> move;
	}

	

	bool move_is_not_valid() const
	{
		if (is_valid()) return false;
		print("Ungueltiger Zug!");
		return true;
	}


	void terminate_move(const std::string &player_name)
	{
		update_game_state();
		show_gameover_message_when_game_is_over(player_name);
	}
	void show_gameover_message_when_game_is_over(const std::string &player_name)
	{
		if (is_gameover())
		{
			print(player_name + " hat verloren");
		}
	}
	bool is_valid() const
	{
		return move >= 1 && move <= 3;
	}
	void update_game_state()
	{
		stones -= move;
	}

	void print(const std::string &message) const
	{
		std::cout << message << std::endl;
	}
	
public:
	takegame_impl(): stones(23)
	{
	}

	

	void play() override
	{
		while( ! is_gameover())
		{
			do_moves();
		}
	}
};

