#pragma once
#include <iostream>
#include <string>

class Battery
{
	int level = 100;
public:
	Battery();
	bool powerConsumption();
	void charge();
};
class Pet
{
	static int animalQty;
	std::string name{};
	int hunger = 0;
	int boredom = 0;
	Pet* mate = nullptr;
protected:
	Battery b;
	void passTime();
public:
	Pet(std::string _name);
	virtual ~Pet();
	static int getNoOfPets();
	std::string mood();
	std::string getName();
	virtual std::string talk();
	void eat(int food);
	void play(int fun);
	void setMate(Pet* mate);
	Pet* getMate() const
	{
		return mate;
	}
	Battery* getBattery();

};

class Cat : public Pet
{
public:
	Cat(std::string _name);
	virtual std::string talk();
};
class Dog : public Pet
{
public:
	Dog(std::string _name);
	virtual std::string talk();
};

std::ostream& operator<<(std::ostream& s, Pet& pet);
Pet* promptPets(Pet** pets);