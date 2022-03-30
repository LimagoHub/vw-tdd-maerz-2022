// Nimmspiel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "takegame_impl.h"
#include "game_client.h"

int main()
{
    takegame_impl game;
	game_client client{ game };
	client.go();
}

