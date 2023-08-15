#pragma once
class State;
#include <stack>
#include "State.h"



class GameStateManager
{
private:
    std::stack<State*> states;
    GameStateManager(); 

public:
    static GameStateManager& getInstance();

    void push(State* state);
    void pop();
    State* peek();
    void setState(State* state);
    void run();
};
