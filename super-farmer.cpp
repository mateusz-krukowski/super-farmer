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
    GameStateManager* gameStateManager = &GameStateManager::getInstance();
    
    SetWindowSize(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT);
    SetWindowPosition((GetMonitorWidth(0) * 0.5f) - (Game::SCREEN_WIDTH * 0.5f), (GetMonitorHeight(0) * 0.5f) -(Game::SCREEN_HEIGHT * 0.5f) );

    while (!WindowShouldClose()) {
        BeginDrawing();
        gameStateManager->draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

