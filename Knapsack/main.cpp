#include "Knapsack.hpp"
#include <iostream>

int main()
{
	//Backpack backpack
	//Robber robber(30, backpack);
	Robber robber(30); // inicjalizacje
	Shop shop;
	std::cout << shop;
	std::cout << robber;
	/*robber.robWhatever(shop);*/
	robber.robGreedy(shop);
	std::cout << "Value of backpack: " << robber.getValue() << std::endl;
	std::cout << shop;
	std::cout << robber;

	return 0;
}

//robber.rob___
//peak ze sklepu - jesli sie miesci to
	//steal ze sklepu
	//put do plecaka



