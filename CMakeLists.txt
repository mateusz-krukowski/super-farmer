cmake_minimum_required(VERSION 3.26)
project(super_farmer)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include/raylib/include)
link_directories(/usr/include/raylib/lib)
include_directories(.)
include_directories(states)


add_executable(super_farmer
        states/GameStateManager.cpp
        states/GameStateManager.h
        states/MenuState.cpp
        states/MenuState.h
        states/State.cpp
        states/State.h
        states/ThrowState.cpp
        states/ThrowState.h
        states/TradeState.cpp
        states/TradeState.h
        Animal.cpp
        Animal.h
        AssetManager.cpp
        AssetManager.h
        Colors.h
        Dice.cpp
        Dice.h
        Game.h
        GreenDice.cpp
        GreenDice.h
        Player.cpp
        Player.h
        RedDice.cpp
        RedDice.h
        super-farmer.cpp
        super-farmer.rc)

