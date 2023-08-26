#include <raygui.h>
#include <iostream>
#include "MenuState.h"
#include "GameStateManager.h"
#include "ThrowState.h"

MenuState::MenuState(GameStateManager* gameStateManager, AssetManager* assetManager) : State(gameStateManager, assetManager)
{
	
	this->textSize = MeasureTextEx(assetManager->AtticAntique, TITLE, fontSize, 0);
	this->fontPosition.x = (Game::SCREEN_WIDTH * 0.5f) - (textSize.x * 0.5f);
	this->fontPosition.y = (Game::SCREEN_HEIGHT * 0.5f) - (textSize.y * 3.5f);

    int buttonWidth = 150;
    int buttonHeight = 40;
    int buttonSpacing = Game::SCREEN_HEIGHT * 0.06f;
    int numButtons = 4;
    int totalHeight = (buttonHeight + buttonSpacing) * numButtons;
    int startY = Game::SCREEN_HEIGHT * 0.5f - totalHeight * 0.5f;

    for (int i = 0; i < numButtons; i++) {
        Rectangle buttonRect = {
            (Game::SCREEN_WIDTH - buttonWidth) * 0.5f,
            startY + i * (buttonHeight + buttonSpacing),
            buttonWidth,
            buttonHeight
        };

        buttons.push_back(buttonRect);
    }

}

void MenuState::draw()
{
	GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER); // raygui

	ClearBackground(Colors::BACKGROUND_COLOR);
	DrawTextEx(assetManager->AtticAntique, TITLE, fontPosition, fontSize, 0, Colors::TITLE_COLOR);

	if (IsKeyPressed(KEY_ENTER)) {
		gameStateManager->setState(new ThrowState(gameStateManager, assetManager));
	}

    for (size_t i = 0; i < buttons.size(); i++) {
        const char* buttonText;

        switch (i) {
        case 0:
            buttonText = "Start";break;
        case 1:
            buttonText = "Settings";break;
        case 2:
            buttonText = "Credits";break;
        case 3:
            buttonText = "Exit";break;
        }

        if (GuiButton(buttons[i], buttonText)) {
            if (i == 0) {
                gameStateManager->setState(new ThrowState(gameStateManager, assetManager));
            }
            if (i == 3) {
                std::cout << "Exit";
                gameStateManager->pop();
            }
            // Add conditions for other buttons similarly
        }
    }

}

void MenuState::run() {

}