#pragma once
#include "State.h"

class ThrowState : public State
{
public:
	ThrowState(GameStateManager* gameStateManager);
	void run() override;
};

