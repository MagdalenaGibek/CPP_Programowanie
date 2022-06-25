
#include <iostream>
#include "BlackBoxGuess.hpp"

int main()
{
	std::cout << "Podaj zakres liczb: ";
	int range;
	std::cin >> range;
	BlackBoxGuess box(50); // should be parametriezed
	int result;
	do
	{
		std::cout << "Podaj liczbę: ";
		int chosenNumber;
		std::cin >> chosenNumber;
		result = box.is(chosenNumber);
		if (result < 0)
		{
			std::cout << "Moja sekretna liczba jest mniejsza" << std::endl;
		}
		else if (result == 0)
		{
			std::cout << "Gratulacje zgadłeś" << std::endl;
		
		}
		else
		{
			std::cout << "Moja sekretna liczba jest większa" << std::endl;
		}
	} while (result != 0);

}


