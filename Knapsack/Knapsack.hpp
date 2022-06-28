#pragma once
#include <iostream>

struct Item
{
	int weight; //kg
	int value;
};

class Shop
{
	Item items[10];
public:
	Shop(); // konstruktor powinien wypelniac tablice przedmiotow - losowymi przedmiotami
	Item steal(int index); //kradnij - odejmij od tablicy
	Item peek(int index); //zajrzyj - sprawdz nie zabieraj ze sklepu
	Item* getItems() const;
};

class Backpack
{
	const int capacity; //15kg
	Item stolen[10];
	int currentCapacity = 0;
	int firstAvailableIndex = 0;
	//int value;
public:
	Backpack(int capacity); //zainicjalizowac naszego consta (lista inicjalizujaca)
	int calculateCurrentValue() const; // zwraca wartosc plecaka
	int put(Item item); // zwraca ile miejsca zostalo w plecaku
	Item* getItems() const;
	bool fits(int weight);
};

class Robber
{
	Backpack backpack; //plecak powininen byc skonstruowany w konstruktorze zlodzieja
public:
	Robber(int capacity); //powinien zainicjalizowac plecak odpowiednia pojemnoscia
	//sklep powinien byc przekazany do zlodzieja
	void robWhatever(Shop& shop); //logika 1 - pierwsze lepsze
	//void robRandom(); //losowo
	void robGreedy(Shop& shop); //logika 2 - wg efektywnosci
	int getValue();
	Item* getBackpackItems() const;
};

//operator<<
//Robber r;
//std::cout << r

//operator!
//!r => policjant

std::ostream& operator<<(std::ostream& s, const Robber& r);
std::ostream& operator<<(std::ostream& s, const Shop& r);


