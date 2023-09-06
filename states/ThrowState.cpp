#include <iostream>
#include <string>
#include <raylib.h>

#include "ThrowState.h"
#include "../Dice.h"
#include "TradeState.h"
#include "GameStateManager.h"


ThrowState::ThrowState(GameStateManager* gameStateManager) : State(gameStateManager)
{	
	
	
}
ThrowState::ThrowState(GameStateManager* gameStateManager, AssetManager* assetManager) : State(gameStateManager, assetManager)
{
	this->textSize = MeasureTextEx(assetManager->AtticAntique, TITLE, fontSize, 0);
	this->fontPosition.x = (Game::SCREEN_WIDTH * 0.5f) - (textSize.x * 0.5f);
	this->fontPosition.y = (Game::SCREEN_HEIGHT * 0.5f) - (textSize.y * 8.8f);
}
void ThrowState::draw()
{
	//draw title 
	ClearBackground(Colors::BACKGROUND_COLOR);
	DrawTextEx(assetManager->AtticAntique, TITLE, fontPosition, fontSize, 0, BLACK);

	//draw dices
	DrawRectangle(
		(Game::SCREEN_WIDTH / 2.0) - (Dice::size / 2.0) - Dice::size - 10,
		(Game::SCREEN_HEIGHT / 2.0)  - (Dice::size / 2.0),
		Dice::size,
		Dice::size,
		Colors::RED_DICE
	);

	DrawRectangle(
		(Game::SCREEN_WIDTH / 2.0) - (Dice::size / 2.0) + Dice::size + 10,
		(Game::SCREEN_HEIGHT / 2.0) - (Dice::size / 2.0),
		Dice::size,
		Dice::size,
		Colors::GREEN_DICE
	);

	// draw animal tiles

	if (IsKeyPressed(KEY_ESCAPE)) {
		gameStateManager->setState(new MenuState(gameStateManager, assetManager));
	}
}
void ThrowState::run()
{
	//bool run = true;
	//bool hasRolledDice = false;
	//std::string input;
	//while (run) {
	//	std::cout << player->toString() << std::endl;
	//	std::cin >> input;
	//	
	//	if (input == "dupa") { run = false; }
	//	else if (input == "r")
	//	{
	//		if (!hasRolledDice) 
	//		{ 
	//			player->rollTheDice(); 
	//			hasRolledDice = true;
	//		}
	//		else std::cout << "You have already rolled the dice this round" << std::endl;
	//	}
	//	else if (input == "z") {
	//		if (hasRolledDice) {
	//			run = false;
	//			gameStateManager->setState(new TradeState(player, gameStateManager));
	//		}
	//		else {
	//			std::cout << "You need to roll the dice first" << std::endl;
	//		}
	//	}
	//}
}

