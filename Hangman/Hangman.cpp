#include "Hangman.h"

Hangman::Hangman(std::string secret)
{
	this->secret = secret;
	this->guessedWord = secret;
	for (int i = 0; i < secret.length(); i++)
	{
		guessedWord[i] = '_';
	}
	for (int i = 0; i < 26; i++)
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
	for (int i = 0; i < 26; i++)
	{
		//if (alphabet[i] == false) // tak raczej nie piszemy - to samo co nizej
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

bool Hangman::guess(char c)
{
	//for (int i = 0; i < 26; i++)
	//{
	//	if ('a' + i == c)
	//	{
	//		alphabet[i] = true;
	//	}
	//}
	//linijka nizej robi to co petla wyzej
	alphabet[c - 'a'] = true; // int index = c - 'a'
	for (int i = 0; i < secret.length(); i++)
	{
		if (secret[i] == c)
		{
			guessedWord[i] = c;
		}
	}
	//bool result = (guessedWord == secret); // to samo co ponizej
	return guessedWord == secret;
}

std::string Hangman::getSecret()
{
	return secret;
}

