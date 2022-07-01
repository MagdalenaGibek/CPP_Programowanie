#pragma once
#include <iostream>
#include "UniversityManagement.hpp"

double University::calculateEmployerCost()
{
	double sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += staff[i]->calculateEmployerCost();
	}
	return sum;
}


void University::printTeachingStaff()
{
	for (int i = 0; i < count; ++i)
	{
		if(staff[i]->isTeachingStaff())
		std::cout << staff[i]->getName() << " " << staff[i]->getSurname() << std::endl;
	}
}

void University::printAllStaffNetIncomes()
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << staff[i]->getName() << " - " << staff[i]->getSurname() << " - " << staff[i]->getEmployeeNetSalary() << std::endl;
	}
	
}

void University::add(Employee* object)
{
	staff[count] = object;
	++count;
}

University::~University()
{
	for (int i = 0; i < count; ++i)
	{
		delete staff[i];
	}
}

Employee::Employee(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : name(_name), surname(_surname), form(_form), salary(_salary)
{
}

double Employee::calculateEmployerCost()
{
	double employerCost = 0;

	switch (form)
	{
	case 0:
		employerCost = (salary * hoursPerMonth) + 0, 23 * (salary * hoursPerMonth);
		break;
	case 1:
		employerCost = salary;
		break;
	case 2:
		employerCost = salary + 0, 15 * salary;
	}
	return employerCost;
}

double Employee::getEmployeeNetSalary()
{
	double pensionInsurance = 0.15;
	double healthInsurance = 0.12;
	double netSalary = salary - pensionInsurance - healthInsurance;

	return netSalary;
}

Professor::Professor(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Professor::isTeachingStaff()
{
	return true;
}

Lecturer::Lecturer(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}


bool Lecturer::isTeachingStaff()
{
	return true;
}

Assistant::Assistant(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Assistant::isTeachingStaff()
{
	return true;
}

Keeper::Keeper(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Keeper::isTeachingStaff()
{
	return false;
} 

Guard::Guard(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Guard::isTeachingStaff()
{
	return false;
}

std::string Employee::getName()
{
	return name;
}

std::string Employee::getSurname()
{
	return surname;
}

