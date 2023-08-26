#define RAYGUI_IMPLEMENTATION
#include <iostream>
#include <string.h>
#include <vector>

#include <raylib.h>
#include <raygui.h>

#include "Game.h"
#include "Colors.h"
#include "Player.h"
#include "GreenDice.h"
#include "RedDice.h"
#include "AssetManager.h"
#include "states/State.h"
#include "states/GameStateManager.h"
#include "states/ThrowState.h"

int main(void)
{ 
    InitWindow(0,0, "Super Farmer");
    SetExitKey(KEY_NULL); // prevent from exiting with ESC which is set by default

    GuiLoadStyle("assets/super-farmer.rgs");
    GameStateManager* gameStateManager = &GameStateManager::getInstance();
    
    SetWindowSize(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT);
    SetWindowPosition((GetMonitorWidth(0) * 0.5f) - (Game::SCREEN_WIDTH * 0.5f), (GetMonitorHeight(0) * 0.5f) -(Game::SCREEN_HEIGHT * 0.5f) );

    
    while (Game::run) {
        BeginDrawing();
        gameStateManager->draw();
        if ( !gameStateManager->peek() || WindowShouldClose() ) Game::run = false;
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

