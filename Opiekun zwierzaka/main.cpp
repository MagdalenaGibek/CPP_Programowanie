#include "Opiekun zwierzaka.hpp"
#include <iostream>

int main()
{
    Pet puppy("Reksio");
    int choice = 0;
    int food = 0;
    int fun = 0;
    do
    {
        std::cout << "Co chcesz zrobić ze swoim zwierzakiem?" << std::endl;
        std::cout << "Wybierz jedną z poniższtych opcji:" << std::endl;
        std::cout << "\t 1 - słuchaj zwierzaka" << std::endl;
        std::cout << "\t 2 - nakarm zwierzaka" << std::endl;
        std::cout << "\t 3 - pobaw sie z zwierzakiem" << std::endl;
        std::cout << "\t 0 - zakończ" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            std::cout<<puppy.talk();
            break;
        case 2:
            std::cout << "Ile jedzenia chcesz dać zwierzakowi?" << std::endl;
            std::cin >> food;
            puppy.eat(food);
            break;
        case 3:
            std::cout << "Ile chcesz się bawić ze zwierzakiem?" << std::endl;
            std::cin >> fun;
            puppy.play(fun);
            break;
        default:
            std::cout << "Błędny wybór." << std::endl;
            break;
        }
    } while (choice != 0);
}


