
#include "BlackBoxGuess.hpp";
#include <iostream>

int main()
{
	std::cout << "Podaj zakres liczb: ";
	int range;
	std::cin >> range;
	BlackBoxGuess box(range); //parameterized
	int result;
	do
	{
		std::cout << "Podaj liczbe: ";
		int chosenNumber;
		std::cin >> chosenNumber;
		result = box.is(chosenNumber);
		if (result < 0)
		{
			std::cout << "Moja sekretna liczba jest mniejsza" << std::endl;
		}
		else if (result == 0)
		{
			std::cout << "Gratulacje! Zgadlas" << std::endl;
		}
		else
		{
			std::cout << "Moja sekretna liczba jest wieksza" << std::endl;
		}
	} while (result != 0);
	return 0;
}


