#pragma once
class State;
class AssetManager;
#include <stack>
#include "State.h"
#include "MenuState.h"
#include "../AssetManager.h"

class GameStateManager
{
private:
    GameStateManager();
    AssetManager* assetManager;
    std::stack<State*> states;


public:
    static GameStateManager& getInstance();

    void draw();

    void push(State* state);
    void pop();
    State* peek();
    void setState(State* state);
    void run();
};
