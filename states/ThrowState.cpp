#include <iostream>
#include <string>

#include "ThrowState.h"
#include "TradeState.h"
#include "GameStateManager.h"


ThrowState::ThrowState(GameStateManager* gameStateManager) : State(gameStateManager)
{	
	
	std::cout << "ThrowState" << std::endl;
}
void ThrowState::run()
{
	//bool run = true;
	//bool hasRolledDice = false;
	//std::string input;
	//while (run) {
	//	std::cout << player->toString() << std::endl;
	//	std::cin >> input;
	//	
	//	if (input == "dupa") { run = false; }
	//	else if (input == "r")
	//	{
	//		if (!hasRolledDice) 
	//		{ 
	//			player->rollTheDice(); 
	//			hasRolledDice = true;
	//		}
	//		else std::cout << "You have already rolled the dice this round" << std::endl;
	//	}
	//	else if (input == "z") {
	//		if (hasRolledDice) {
	//			run = false;
	//			gameStateManager->setState(new TradeState(player, gameStateManager));
	//		}
	//		else {
	//			std::cout << "You need to roll the dice first" << std::endl;
	//		}
	//	}
	//}
}

