#pragma once
#include <string>
class Hangman
{
	std::string secret;
	bool alphabet[26];
	std::string guessedWord;
	int attempts=5;
public:
	Hangman(std::string secret);
	std::string getGuess();
	std::string getAlphabet();
	std::string getSecret();
	bool guess(char c);
	int attemptsLeft();

};