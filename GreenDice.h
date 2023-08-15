#pragma once
#include "Dice.h"
#include "Animal.h"
class GreenDice : public Dice
{
private:
	GreenDice();

public:
	static GreenDice& getInstance();
	Animal roll() override;
};

