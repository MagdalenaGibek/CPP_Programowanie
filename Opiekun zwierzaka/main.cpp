#include "Opiekun zwierzaka.hpp"
#include <iostream>

int main(){
    Pet pupil("Szczurek");
    Cat kitten("Mruczek");
    Dog puppy("Reksio");

    Pet** pets = new Pet*[3];
    pets[0] = &pupil;
    pets[1] = &kitten;
    pets[2] = &puppy;
   
    pupil.setMate(&kitten); // ASOCJACJA
    kitten.setMate(&pupil);
    

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
        std::cout << "\t 4 - doładuj zwierzaka" << std::endl;
        std::cout << "\t 5 - pokaż, przyjaciela zwierzaka" << std::endl;
        std::cout << "\t 0 - zakończ" << std::endl;
        std::cin >> choice;

        Pet* chosenPet = nullptr;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            chosenPet = promptPets(pets);
            std::cout<< chosenPet->talk();
            break;
        case 2:
            chosenPet = promptPets(pets);
            std::cout << "Ile jedzenia chcesz dać zwierzakowi?" << std::endl;
            std::cin >> food;
            chosenPet->eat(food);
            break;
        case 3:
            chosenPet = promptPets(pets);
            std::cout << "Ile chcesz się bawić ze zwierzakiem?" << std::endl;
            std::cin >> fun;
            chosenPet->play(fun);
            break;
        case 4:
            chosenPet = promptPets(pets);
            chosenPet->getBattery()->charge();
            break;
        case 5: 
            chosenPet = promptPets(pets);
            if (chosenPet->getMate() != nullptr)
            {
                std::cout << "Przyjacielem " << chosenPet->getName() << " jest " << chosenPet->getMate()->getName() << std::endl << std::endl;
            }
            else
            {
                std::cout<<"Ten zwierzak nie ma przyjaciela :(." << std::endl << std::endl;
            }
            break;
        default:
            std::cout << "Błędny wybór." << std::endl;
            break;
        }
    } while (choice != 0);
}


