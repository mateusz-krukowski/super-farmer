cmake_minimum_required(VERSION 3.26)
project(super-farmer)
set(CMAKE_CXX_STANDARD 14)

add_executable(super-farmer
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

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
target_include_directories(super-farmer PRIVATE "/usr/include/raylib/include")
target_link_libraries(super-farmer "/usr/include/raylib/lib/libraylib.a")
