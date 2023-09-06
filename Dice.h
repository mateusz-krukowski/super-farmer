#pragma once
#include <random>
#include "Animal.h"


class Dice
{
	public:
		static const int size = 80;
		Dice();
		virtual Animal roll()  = 0;
};

