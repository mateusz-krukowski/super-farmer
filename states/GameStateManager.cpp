#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    states = std::stack<State*>();
}

GameStateManager& GameStateManager::getInstance()
{
    static GameStateManager instance;  // Jedyna instancja klasy
    return instance;
}

void GameStateManager::push(State* state)
{
    states.push(state);
}

void GameStateManager::pop()
{
    states.pop();
}

State* GameStateManager::peek()
{
    if (!states.empty())
    {
        return states.top();
    }
    return nullptr;
}

void GameStateManager::setState(State* state)
{
    if(!(states.empty())){
        pop();
    }
    push(state);

}

void GameStateManager::run()
{
    try
    {
        this->peek()->run();
    }
    catch (const std::exception&)
    {

    }
}
