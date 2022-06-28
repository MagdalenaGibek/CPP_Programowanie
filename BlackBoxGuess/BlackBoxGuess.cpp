#include "BlackBoxGuess.hpp"
#include <random>

BlackBoxGuess::BlackBoxGuess(int range)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, range); // define the range

    this->hiddenNumber = distr(gen);
}

int BlackBoxGuess::is(int guess)
{
    if (hiddenNumber < guess)
        return -1;
    else if (hiddenNumber == guess)
        return 0;
    else
        return 1;

    //return hiddenNumber-guess;
}

