#pragma once
#include "State.h"
#include "../Game.h"
#include "../Colors.h"
#include "../AssetManager.h"

class ThrowState : public State
{
private:
	const char TITLE[50] = "    Throw\nState";
	Vector2 fontPosition = { 0,0 };
	Vector2 textSize = { 0.0f, 0.0f };
	float fontSize = Game::SCREEN_HEIGHT * 0.05f;
public:
	ThrowState(GameStateManager* gameStateManager);
	ThrowState(GameStateManager* gameStateManager, AssetManager* assetManager);
	void draw() override;
	void run() override;
};

