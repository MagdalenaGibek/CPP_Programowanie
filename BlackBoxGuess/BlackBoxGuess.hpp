#pragma once

class BlackBoxGuess
{
	int hiddenNumber;
public:
	BlackBoxGuess(int range); //hiddenNumber to be generated out of <0,range>
	int is(int guess); //returns -1 if our number is smaller, 0-larger, 1 if larger
};
