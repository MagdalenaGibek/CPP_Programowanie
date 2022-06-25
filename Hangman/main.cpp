#include "Hangman.h"
#include <iostream>


int main()
{
	Hangman game("wisielec");
	bool finished = false;

	   do
	   {
		   std::string guess = game.getGuess();
		   std::cout << guess << std::endl;
		   std::string alphabet = game.getAlphabet();
		   std::cout << alphabet << std::endl;

		   std::cout << "Guess a letter: ";
		   char letter;
		   std::cin >> letter;

		   finished = game.guess(letter);

		   
	   } while (!(finished || game.attemptsLeft()==0)); 
std::cout << "Secret key was: " << game.getSecret();

}


