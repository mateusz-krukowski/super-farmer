#include <iostream>
#include <string>

#include "ThrowState.h"
#include "TradeState.h"

TradeState::TradeState(Player* player, GameStateManager* gameStateManager)
{
	std::cout << "TradeState" << std::endl;
}
void TradeState::run()
{
	bool run = true;
	bool hasRolledDice = false;
	std::string input;
	while (run) {
		std::cout << player->toString() << std::endl;
		std::cin >> input;
		if (input == "dupa") { run = false; }

	}
}
