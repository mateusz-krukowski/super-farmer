#include "MenuState.h"


MenuState::MenuState(GameStateManager* gameStateManager, AssetManager* assetManager) : State(gameStateManager, assetManager)
{

}

void MenuState::draw() 
{   
	textSize = MeasureTextEx(assetManager->AtticAntique, TITLE, fontSize , 0);
	fontPosition.x = (Game::SCREEN_WIDTH * 0.5f) - (textSize.x * 0.5f);
	fontPosition.y = (Game::SCREEN_HEIGHT * 0.5f) - (textSize.y *3.5f);
	BeginDrawing();

	ClearBackground(Colors::BACKGROUND_COLOR);
	DrawTextEx(assetManager->AtticAntique, TITLE, fontPosition, fontSize, 0, Colors::TITLE_COLOR);


	EndDrawing();

}