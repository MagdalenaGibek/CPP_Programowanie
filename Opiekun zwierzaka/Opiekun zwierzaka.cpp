#include "Opiekun zwierzaka.hpp"
#include <sstream>

int Pet::animalQty = 0;

void Pet::passTime()
{
    ++hunger;
    ++boredom;
}

Pet::Pet(std::string _name) : name(_name)
{
    ++animalQty;
}

int Pet::getNoOfPets()
{
    return animalQty;
}

Pet::~Pet()
{
    --animalQty;
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
    if (b.powerConsumption())
    {
        s << "Nazywam się " << getName() << " i jestem " << mood() << " teraz." << std::endl << std::endl;
        passTime();
    }
    else
    {
        s << "Za niski poziom baterii. Doładuj zwierzaka."<<std::endl<<std::endl;
    }
    return s.str();
}

void Pet::eat(int food)
{
    if (b.powerConsumption())
    {
        std::cout << "Miniam, mniam. Dziekuję." << std::endl << std::endl;
        hunger -= food;
        if (hunger < 0)
        {
            hunger = 0;
        }
        passTime();
    }
    else
    {
        std::cout << "Za niski poziom baterii. Doładuj zwierzaka." << std::endl << std::endl;
    }
}

void Pet::play(int fun)
{
    if (b.powerConsumption())
    {
        std::cout << "Hurra!" << std::endl << std::endl;
        boredom -= fun;
        if (boredom < 0)
        {
            boredom = 0;
        }
        passTime();
    }
    else
    {
        std::cout << "Za niski poziom baterii. Doładuj zwierzaka." << std::endl << std::endl;
    }
}

void Pet::setMate(Pet* _mate)
{
    mate = _mate;
}

Battery* Pet::getBattery()
{
    return &b;
}

std::ostream& operator<<(std::ostream& s, Pet& pet)
{
    return s << pet.talk();
}

Battery::Battery()
{
}

bool Battery::powerConsumption()
{
    if (level < 20)
    {
        return false;
    }
    else
    {
        level -= 20;
        return true;
    }
}

void Battery::charge()
{
    level = 100;
}

Cat::Cat(std::string _name) : Pet(_name)
{
}

std::string Cat::talk()
{
    std::ostringstream s;
    if (b.powerConsumption())
    {
        s << "Miau, miau! Nazywam się " << getName() << " i jestem " << mood() << " teraz." << std::endl << std::endl;
        passTime();
    }
    else
    {
        s << "Za niski poziom baterii. Doładuj zwierzaka." << std::endl << std::endl;
    }
    return s.str();
}

Dog::Dog(std::string _name): Pet(_name)
{
}

std::string Dog::talk()
{
    std::ostringstream s;
    if (b.powerConsumption())
    {
        s << "How, how! Nazywam się " << getName() << " i jestem " << mood() << " teraz." << std::endl << std::endl;
        passTime();
    }
    else
    {
        s << "Za niski poziom baterii. Doładuj zwierzaka." << std::endl << std::endl;
    }
    return s.str();
}

Pet* promptPets(Pet** pets)
{
    Pet* choosenPet = 0;

    while (choosenPet == 0)
    {
        std::cout << "Ktore zwierzę wybierasz?" << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            std::cout << i << " - " << pets[i]->getName() << std::endl;
        }

        int number;
        std::cin >> number;

        if (number >= 0 && number < 3)
        {
            choosenPet = pets[number];
        }
    }

    return choosenPet;

}