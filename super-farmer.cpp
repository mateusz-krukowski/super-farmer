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
    //niech kostki beda statyczne moze idk

    for (int i = 0; i < player_num; i++) {
        players.emplace_back(i);
    }
  

    while (run) {
        
        Player* currentPlayer = &players[currentIndex];
        gameStateManager->setState(new ThrowState(currentPlayer,gameStateManager));
        gameStateManager->run();

        std::string input;
        std::cout << "main loop" << std::endl;
        std::cin >> input;
        std::cout << currentIndex;
        currentIndex = (currentIndex + 1) % players.size();
        if (input == "dupa") run = false;
    }

    return 0;
}

