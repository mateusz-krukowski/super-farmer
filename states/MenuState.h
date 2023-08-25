#pragma once
#include <vector>
#include "raygui.h"
#include "State.h"
#include "../Game.h"
#include "../Colors.h"
#include "../AssetManager.h"

class MenuState : public State
{

private:
	const char TITLE[50] = "   super\nFARMER";
	Vector2 fontPosition = { 0,0 };
	Vector2 textSize = { 0.0f, 0.0f };
	float fontSize = Game::SCREEN_HEIGHT * 0.05f;
	std::vector<Rectangle> buttons = {};
public:
	MenuState(GameStateManager* gameStateManager, AssetManager* assetManager);
	void draw() override;
	void run() override;
};
