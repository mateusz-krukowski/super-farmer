#include "State.h"

State::State()
{
}

State::State(Player* player, GameStateManager* gameStateManager)
{

	this->player = player;
	this->gameStateManager = gameStateManager;
}
State::~State()
{
}

void State::run()
{
}
