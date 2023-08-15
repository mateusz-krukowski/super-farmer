#include <iostream>
#include <string>

#include "Dice.h"
#include "RedDice.h"
#include "GreenDice.h"

#pragma once

class Player
{
private:
    RedDice* redDice;
    GreenDice* greenDice;
	bool smallDog;
	bool bigDog;
	unsigned char index;
	unsigned char rabbits;
	unsigned char sheeps;
	unsigned char pigs;
	unsigned char cows;
	unsigned char horses;

public:
	Player(unsigned char index);
	std::string toString() const;
	bool won();
    std::string animalToString(Animal animal);
    void handleDiceOutcome(Animal first, Animal second); //TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void rollTheDice();

    // Getters
    bool hasSmallDog() const;
    bool hasBigDog() const;
    unsigned char getIndex() const;
    unsigned char getRabbits() const;
    unsigned char getSheeps() const;
    unsigned char getPigs() const;
    unsigned char getCows() const;
    unsigned char getHorses() const;

    // Setters
    void setSmallDog(bool value);
    void setBigDog(bool value);
    void setIndex(unsigned char value);
    void setRabbits(unsigned char value);
    void setSheeps(unsigned char value);
    void setPigs(unsigned char value);
    void setCows(unsigned char value);
    void setHorses(unsigned char value);

};

