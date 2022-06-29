#include "Opiekun zwierzaka.hpp"
#include <sstream>

void Pet::passTime()
{
    ++hunger;
    ++boredom;
}

Pet::Pet(std::string _name) : name(_name)
{
}

std::string Pet::mood()
{
    std::string petMood = {};
    int unhappiness = hunger + boredom;
    if (unhappiness < 5)
    {
        petMood = "szczęśliwy";
    }
    else if (unhappiness <= 10)
    {
        petMood = "zadowolony";
    }
    else if (unhappiness <= 15)
    {
        petMood = "podenerwowany";
    }
    else
    {
        petMood = "wściekły";
    }
    return petMood;
}

std::string Pet::getName()
{
    return name;
}


std::string Pet::talk()
{
    std::ostringstream s;
    s << (*this);
    passTime();
    return s.str();
}

int Pet::eat(int food)
{
    std::cout << "Miniam, mniam. Dziekuję."<<std::endl << std::endl;
    hunger -= food;
    if (hunger < 0)
    {
        hunger = 0;
    }
    passTime();
    return hunger;
}

int Pet::play(int fun)
{
    std::cout << "Hurra!" << std::endl << std::endl;
    boredom -= fun;
    if (boredom < 0)
    {
        boredom = 0;
    }
    passTime();
    return boredom;
}

std::ostream& operator<<(std::ostream& s, Pet& pet)
{
    return s << "Nazywam się " << pet.getName() << " i jestem " << pet.mood() << " teraz." << std::endl<< std::endl;
}