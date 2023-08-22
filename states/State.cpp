#include "State.h"


State::State(GameStateManager* gameStateManager, AssetManager* assetManager)
{

	this->gameStateManager = gameStateManager;
	this->assetManager = assetManager;
}

State::State(GameStateManager* gameStateManager)
{
}

State::State()
{
}

State::~State()
{
	this->player = nullptr;
	this->gameStateManager = nullptr;
	this->assetManager = nullptr;
}
