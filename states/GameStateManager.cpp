#include "GameStateManager.h"

GameStateManager::GameStateManager()
{   
    AssetManager* assetManager = &AssetManager::getInstance();
    states = std::stack<State*>();
    this->push(new MenuState(this, assetManager));
}

GameStateManager& GameStateManager::getInstance()
{
    static GameStateManager instance; 
    return instance;
}

void GameStateManager::draw()
{
    this->peek()->draw();
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
