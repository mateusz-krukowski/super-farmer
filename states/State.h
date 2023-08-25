#pragma once
class GameStateManager;
class AssetManager;
class Player;

#include <raylib.h>



class State
{
protected:
	Player* player = nullptr;
	GameStateManager* gameStateManager = nullptr;
	AssetManager* assetManager = nullptr;

public:
	State(GameStateManager* gameStateManager, AssetManager* assetManager);
	State(GameStateManager* gameStateManager);
	State();
	~State();
	virtual void run() = 0;
	virtual void draw() = 0;
};

