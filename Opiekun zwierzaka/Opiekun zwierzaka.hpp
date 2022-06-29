#pragma once
#include <iostream>
#include <string>

class Pet
{
	std::string name{};
	int hunger = 0;
	int boredom = 0;
	void passTime();
public:
	Pet(std::string _name);
	std::string mood();
	std::string getName();
	std::string talk();
	int eat(int food);
	int play(int fun);

};

std::ostream& operator<<(std::ostream& s, Pet& pet);
