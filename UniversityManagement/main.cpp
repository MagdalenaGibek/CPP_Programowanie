#include "UniversityManagement.hpp"
#include <iostream>

int main()
{
	University u;

	Professor *janina = new Professor("Janina", "Abacka", FormOfEmployment::Contract, 60);
	Professor *jan = new Professor("Jan", "Badulski", FormOfEmployment::ContractOfEmployment, 8700);
	Lecturer *krzysztof = new Lecturer("Krzysztof", "Powolski", FormOfEmployment::ContractOfEmployment, 6000);
	Lecturer *karolina = new Lecturer("Karolina", "Szybka", FormOfEmployment::ContractOfEmployment, 5700);
	Assistant *hanna = new Assistant("Hanna", "Nowicjusz", FormOfEmployment::ContractOfMandate, 4500);
	Keeper *tomasz = new Keeper("Tomasz", "Oliwny", FormOfEmployment::ContractOfMandate, 4000);
	Guard *alicja = new Guard("Alicja", "Strazacka", FormOfEmployment::Contract, 24);
	 
	u.add(janina);
	u.add(jan);
	u.add(krzysztof);
	u.add(karolina);
	u.add(hanna);
	u.add(tomasz);
	u.add(alicja);

	//dynamiczne tworzenie obiektu i dodawanie do uniwersytetu w zaleznosci od danych uzytkownika??

	

	std::cout << "Suma wynagrodzen: " << u.calculateEmployerCost() << std::endl;
	std::cout << std::endl;
	std::cout<< "Lista płac: " << std::endl;
	u.printAllStaffNetIncomes();
	std::cout << std::endl;
	std::cout << "Pracownicy naukowi: " << std::endl;
	u.printTeachingStaff();
}
