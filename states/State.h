#pragma once
class GameStateManager;
#include "../Player.h"
#include "GameStateManager.h"



class State
{
protected:
	Player* player = nullptr;
	GameStateManager* gameStateManager = nullptr;

public:
	State();
	State(Player* player, GameStateManager* gameStateManager);
	virtual ~State();
	virtual void run();
};

