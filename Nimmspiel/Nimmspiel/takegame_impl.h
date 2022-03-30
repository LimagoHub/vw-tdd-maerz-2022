#pragma once
#include <iostream>
#include <vector>
#include "game.h"
class takegame_impl: public game
{
private:
	int stones;
	bool gameover;
	
	void computerzug()
	{
		std::vector<int> moves{ 3,1,1,2 };
		if(stones < 1)
		{
			std::cout << "Du loser!" << std::endl;
			gameover = true;
			return;
		}
		if (stones == 1)
		{
			std::cout << "Du hast nut Glueck gehabt!" << std::endl;
			gameover = true;
			return;
		}
		int move = moves[stones % 4];
		std::cout << "Computer nimmt " << move << " Steine." << std::endl;
		stones -= move;
	}

	void spielerzug()
	{
		int move;
		while(true)
		{
			std::cout << " Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
			std::cin >> move;
			if (move >= 1 && move <= 3) break;
			std::cout << "Ungueltiger Zug!";
		}
		stones -= move;
		
	}
	void do_moves()
	{
		spielerzug();
		computerzug();
	}
public:
	takegame_impl():gameover(false), stones(23)
	{
	}

	

	void play() override
	{
		while( ! gameover)
		{
			do_moves();
		}
	}
};

