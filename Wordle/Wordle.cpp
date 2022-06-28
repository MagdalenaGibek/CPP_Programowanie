#include "Wordle.hpp"
#include <iostream>
#include <stdlib.h>

bool Wordle::findIfExists(char c)
{
	for (int i = 0; i < 5; i++)
	{
		if (secret[i] == c)
		{
			return true;
		}
	}
	return false;
}

Wordle::Wordle(std::string secret)
{
	this->secret = secret;
}

std::string Wordle::test(std::string guess)
{
	if (attempt < 6)
	{
		guesses[attempt] = guess;

		//std::string answer(5, 'B'); // nowa zmienna answer o wartosci BBBBB; wersja A
		answers[attempt] = std::string(5, 'B'); // wersja B // Marek
		for (int i = 0; i < 5; i++) // sprawdzamy kazdy znak
		{
			if (secret[i] == guess[i]) // jesli znak w zgadywanym i sekrecie pokrywa sie w 100%
			{
				//answer[i] = 'G'; //podmien w odpowiedzi na 'G'; wersja A
				answers[attempt][i] = 'G'; // wersja B
			}
			else if (findIfExists(guess[i]))
			{
				answers[attempt][i] = 'O';
			}

		}
		//answers[attempt] = answer; // wstaw string z kolorem do tablicy odpowiedzi; wersja A
		attempt++;
		return answers[attempt - 1];
	}
	return std::string(); // ktos probuje odgadnac haslo po 6 probie - nie powinnismys ie tutaj dostac, ale better safe than sorry; przezorny zawsze ubezpieczony
}

void Wordle::draw()
{
	//std::cout << "\033[0;32mOUTPUT \033[0m";
	system("cls");
	for (int i = 0; i < 6; i++) //6 bo mamy 6 wierszy
	{
		//std::cout << "\033[1;31mbold red text\033[0m\n";
		//std::cout << guesses[i] << '\t';
		for (int j = 0; j < answers[i].length(); j++)
		{
			char c = answers[i][j];
			if (c == 'G')
			{
				std::cout << "\033[32m";
			}
			else if (c == 'O')
			{
				std::cout << "\033[33m";
			}
			else
			{
				std::cout << "\033[37m";
			}
			std::cout << guesses[i][j];
			std::cout << "\033[0m";
		}
		std::cout << std::endl;
	}
}

bool Wordle::isFinished()
{
	if (attempt == 0)
		return false;

	return (attempt == 6) || (answers[attempt - 1] == "GGGGG");
	//if (attempt == 6 || answers[attempt - 1] == "GGGGG")
	//	return true;
	//else 
	//	return false;
}
