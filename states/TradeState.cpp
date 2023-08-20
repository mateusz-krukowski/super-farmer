#include <iostream>
#include <string>

#include "ThrowState.h"
#include "TradeState.h"

TradeState::TradeState(Player* player, GameStateManager* gameStateManager) : State(player, gameStateManager)
{
	std::cout << "TradeState" << std::endl;
}
void TradeState::run()
{
	bool run = true;
	char input;
	while (run) {
		std::cout << player->toString() << std::endl;
		std::cin >> input;
		if (input == 'z') { run = false; }

		switch (input) {
			case 'q': player->tradeRabbitsForSheep(); break; // 6 rabbits for sheep
			case 'w': player->tradeSheepForRabbits(); break; // sheep for 6 rabbits

			case 'e': player->tradeSheepForSmallDog(); break; // sheep for small dog
			case 'r': player->tradeSmallDogForSheep(); break; //small dog for sheep

			case 't': player->tradeSheepsForPig(); break; // 2 sheeps for pig
			case 'y': player->tradePigForSheeps(); break; // pig for 2 sheeps

			case 'a': player->tradePigsForCow(); break; // 3 pigs for cow
			case 's': player->tradeCowForPigs(); break; // cow for 3 pigs

			case 'd': player->tradeCowForBigDog() break; //cow for big dog
			case 'f': player->tradeBigDogForCow(); break; //big dog for cow

			case 'g': player->tradeCowsForHorse(); break; // 2 cows for horse 
			case 'h': player->tradeHorseForCows(); break; // horse for 2 cows

		}

	}
}
