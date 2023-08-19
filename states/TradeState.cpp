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
			case 'q': std::cout << input; break; // 6 rabbits for sheep
			case 'w': std::cout << input; break; // sheep for 6 rabbits

			case 'e': std::cout << input; break; //small dog for sheep
			case 'r': std::cout << input; break; // sheep for small dog

			case 't': std::cout << input; break; // 2 sheeps for pig
			case 'y': std::cout << input; break; // pig for 2 sheeps

			case 'a': std::cout << input; break; // 3 pigs for cow
			case 's': std::cout << input; break; // cow for 3 pigs

			case 'd': std::cout << input; break; //cow for big dog
			case 'f': std::cout << input; break; //big dog for cow

			case 'g': std::cout << input; break; // 2 cows for horse 
			case 'h': std::cout << input; break; // horse for 2 cows

			case 'z': run = false; break;

		}

	}
}

void TradeState::tradeRabbitsForSheep()
{
	player->subtractAnimalQuantity(Animal::Rabbit, 6);
	player->addAnimalQuantity(Animal::Sheep, 1);

}

void TradeState::tradeSheepForRabbits()
{
	player->subtractAnimalQuantity(Animal::Sheep, 1);
	player->addAnimalQuantity(Animal::Rabbit, 6);
	
}

void TradeState::tradeSheepForSmallDog()
{
}

void TradeState::tradeSmallDogForSheep()
{
}

void TradeState::tradeSheepsForPig()
{
}

void TradeState::tradePigForSheeps()
{
}

void TradeState::tradePigsForCow()
{
}

void TradeState::tradeCowForBigDog()
{
}

void TradeState::tradeBigDogForCow()
{
}

void TradeState::tradeCowsForHorse()
{
}

void TradeState::tradeHorseForCows()
{
}
