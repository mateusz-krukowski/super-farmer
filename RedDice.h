#pragma once
#include "Dice.h"
#include "Animal.h"
class RedDice : public Dice
{
private:
	RedDice();
public:
	static RedDice& getInstance();
	Animal roll() override;
};

