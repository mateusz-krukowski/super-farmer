#pragma once
#include <random>
#include "Animal.h"


class Dice
{
	public:
		Dice();
		virtual Animal roll()  = 0;
};

