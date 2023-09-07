#include <iostream>
#include <string.h>
#include <vector>

#include "Player.h"
#include "GreenDice.h"
#include "RedDice.h"
#include "states/GameStateManager.h"
#include "states/ThrowState.h"


int main()
{
    bool run = true;
    unsigned char player_num = 4;
    unsigned int currentIndex = 0;

    GameStateManager* gameStateManager = &GameStateManager::getInstance();
    std::vector<Player> players;

    for (int i = 0; i < player_num; i++) {
        players.emplace_back(i);
    }
  

    while (run) {
        
        Player* currentPlayer = &players[currentIndex];
        gameStateManager->setState(new ThrowState(currentPlayer,gameStateManager));
        std::string input;
        std::cout << "main loop" << std::endl;
        std::cin >> input;
        currentIndex = (currentIndex + 1) % players.size();
        if (currentPlayer->won()) { std::cout << "Player " << currentIndex << " won" << std::endl; run = false; }
        if (input == "dupa") run = false;
    }

    return 0;
}

