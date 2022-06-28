#pragma once
#include <string>

class Hangman
{
	std::string secret; //przekazane z konstruktora
	bool alphabet[26]; // warto zainicjalizowac w konstruktorze
	std::string guessedWord; //na samym poczatku bedzie mial same _ _ 
	int attempt; // ignorujemy poki co
public:
	Hangman(std::string secret);
	std::string getGuess();
	std::string getAlphabet();
	//returns true if all characters are guessed
	bool guess(char c);
	std::string getSecret();
};

//zdefiniowac konstruktor: wprowadzic secreta; wypelnic tablice; guessed word - same kreski
