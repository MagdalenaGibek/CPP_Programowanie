#pragma once
#include <string>

#include <stdlib.h> //w .cpp

class Wordle
{
	std::string secret;
	std::string guesses[6];
	std::string answers[6];
	int attempt;
public:
	Wordle(std::string secret);
	std::string test(std::string guess);
	void draw(); // wypisz obie tablice, jedna obok drugiej + na poczatku wyczyscic ekran
	bool isFinished(); // sprawdzamy czy ostatnie zgadniete slowo to secret oraz porownac liczbe attempt
	//bool isFinished(std::string guess); // sprawdzamy czy slowo to secret oraz porownac liczbe attempt
	//bool isFinished(std::string colours); // sprawdzamy czy slowo to "GGGGG"
};

// std::cout << '\t'
// wynik metody draw
//IRATE \t BBGBO
//CEASE \t BGGBB
//HEAVY \t BGGBB
//BEADY \t GGGGG

