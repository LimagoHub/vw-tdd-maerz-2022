#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "game.h"
class takegame_impl: public game
{
	
	int stones;
	int move;

	bool is_gameover()
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
		std::cout << "Computer nimmt " << move << " Steine." << std::endl;
		
		terminate_move("Computer");
	}

	void spielerzug()
	{
		if (is_gameover()) return;
		
		
		while(true)
		{
			std::cout << " Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
			std::cin >> move;
			if (move >= 1 && move <= 3) break;
			std::cout << "Ungueltiger Zug!";
		}
		
		terminate_move("Spieler");
		
	}




	void terminate_move(std::string player_name)
	{
		update_game_state();
		show_gameover_message_when_game_is_over(player_name);
	}
	
	void show_gameover_message_when_game_is_over(std::string player_name)
	{
		if (is_gameover())
		{
			std::cout << player_name << " hat verloren" << std::endl;
		}
	}
	
	void update_game_state()
	{
		stones -= move;
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

