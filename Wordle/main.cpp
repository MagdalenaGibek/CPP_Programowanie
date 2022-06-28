#include "Wordle.hpp"
#include <iostream>

int main()
{
	Wordle game("BEADY");

	do
	{
		std::string word;
		std::cin >> word;
		std::string colours = game.test(word);
		//std::cout << colours << std::endl;
		game.draw();
	} while (!game.isFinished());

	return 0;
}

