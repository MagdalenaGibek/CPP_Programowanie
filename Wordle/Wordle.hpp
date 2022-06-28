#pragma once
#include <string>

#include <stdlib.h> //w .cpp

class Wordle
{
	std::string secret;
	std::string guesses[6]; // slowa
	//std::string firstWord = guesses[0]; 
	//char firstCharFirstWord = firstWord[0];
	//char firstCharFirstWord = guesses[0][0];
	std::string answers[6]; // kolory
	int attempt = 0;
	bool findIfExists(char c);
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

//w konstruktorze
//answers[0] = "GGBGG"
//guesses[0] = "BEADY"

//std::string answer("B",5); -> "BBBBB"
//for (int i = 0; i < 5; i++) answer += "B";

//std::string answer("B",5); BBBBB
//for (int i = 0; i < 5; i++)
//	if (guess[i] == secret[i])
//		answer[i] = 'G';
//  else
//      answer[i] = findIfExists(guess[i])
//answers[attempt] = answer;

//answers[attempt] = std::string("B", 5);
//answers[attempt][i] = 'G'; -> rzuca bledem?
//answers[attempt] -> jest puste
//std::string empty; empty[123451] = 'P'; -> tez rzuci bledem

//char findIfExists(char c) // czy c istnieje w secrecie
//{
//zwraca O - jeeli litera istnieje w secrecie
//zwraca B - jezeli nie istnieje
//petla sprawdzajaca secret i czy c w nim istnieje


//	if (guess[i] == secret[i])
//		answer[i] = "G";
//  else if (findIfExists(guess[i])
//      answer[i] = "O"
// 
//bool findIfExists(char c) {

