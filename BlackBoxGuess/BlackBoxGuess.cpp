#include "BlackBoxGuess.hpp"
#include <iostream>
#include <random>

BlackBoxGuess::BlackBoxGuess(int range)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, range);
	this->hiddenNumber = hiddenNumber;

}

int BlackBoxGuess::is(int guess)
{
	if (guess > hiddenNumber)
	{
		return -1;
	}
	else if (guess < hiddenNumber)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//return hiddenNumber-guess
}
