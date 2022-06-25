#pragma once

class BlackBoxGuess
{
	int hiddenNumber;
public:
	BlackBoxGuess(int range); //hidden number to be generated
	int is(int guess); //retruns -1 if number is smaller, 0-larger, 1 if larger 

};