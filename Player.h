#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>


#include "Dice.h"
#include "RedDice.h"
#include "GreenDice.h"

#pragma once

class Player
{
private:
    unsigned char index;
    RedDice* redDice;
    GreenDice* greenDice;
	bool smallDog;
	bool bigDog;
    std::unordered_map<Animal, unsigned char> animals;

public:
	Player(unsigned char index);
	std::string toString() const;
	bool won();
    std::string animalToString(Animal* animal);
    void addAnimalQuantity(Animal animal, unsigned char quantity);
    void subtractAnimalQuantity(Animal animal, unsigned char quantity);
    void handleDiceOutcome(Animal red, Animal green);
    void rollTheDice();
    void handleRolledAnimalOnce(Animal animal);
    void handleRolledAnimalTwice(Animal animal);

    // performing trades
    void tradeRabbitsForSheep();
    void tradeSheepForRabbits();
    void tradeSheepForSmallDog();
    void tradeSmallDogForSheep();
    void tradeSheepsForPig();
    void tradePigForSheeps();
    void tradePigsForCow();
    void tradeCowForPigs();
    void tradeCowForBigDog();
    void tradeBigDogForCow();
    void tradeCowsForHorse();
    void tradeHorseForCows();

    // Getters
    bool hasSmallDog() const;
    bool hasBigDog() const;
    std::unordered_map<Animal, unsigned char>& getAnimals() const;

    // Setters
    void setSmallDog(bool value);
    void setBigDog(bool value);
    void setAnimalQuantity(Animal animal, unsigned char quantity);

};

