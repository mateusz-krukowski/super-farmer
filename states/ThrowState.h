#pragma once
#include "State.h"
class ThrowState : public State
{
public:
	ThrowState(Player* player, GameStateManager* gameStateManager);
	void run() override;
};

