#include "Hangman.h"

Hangman::Hangman(std::string secret)
{
	this->secret = secret;
	guessedWord = secret;
	for (int i = 0; i < secret.length(); ++i)
	{
		guessedWord[i] = '_';
	}
	for (int i = 0; i < 26; ++i)
	{
		alphabet[i] = false;
	}
}

std::string Hangman::getGuess()
{
	return guessedWord;
}

std::string Hangman::getAlphabet()
{
	std::string result;
	for (int i = 0; i < 26; ++i)
	{
		if (!alphabet[i])
		{
			result += 'a' + i;
		}
		else
		{
			result += '_';
		}
	}
	
	return result;
}

std::string Hangman::getSecret()
{
	return secret;
}

bool Hangman::guess(char c)
{
	c = tolower(c);
	alphabet[c - 'a'] = true;
	for (int i = 0; i < secret.length(); ++i)
	{
		if (secret[i] == c)
		{
			guessedWord[i] = c;
		}
	}

	--attempts;

	return guessedWord == secret;
}

int Hangman::attemptsLeft()
{
	return attempts;
}
