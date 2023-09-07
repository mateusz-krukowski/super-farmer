cmake_minimum_required(VERSION 3.10)
project(SuperFarmer)

set(SOURCE_FILES
        super-farmer.cpp
        RedDice.cpp
        GreenDice.cpp
        Player.cpp
        Dice.cpp
        Animal.cpp
        states/State.cpp
        states/GameStateManager.cpp
        states/ThrowState.cpp
        states/TradeState.cpp
)

set(HEADER_FILES
        RedDice.h
        GreenDice.h
        Player.h
        Dice.h
        Animal.h
        states/State.h
        states/GameStateManager.h
        states/ThrowState.h
        states/TradeState.h
)

add_executable(SuperFarmer ${SOURCE_FILES} ${HEADER_FILES})