#include "MyString.hpp"

MyString::MyString()
{
	this->arr = new char[1]; //1-elementowa tablica // Marek
	this->arr[0] = '\0';
}

MyString::MyString(char* input)
{
	int length = std::strlen(input);
	//this->arr = input; // unikamy - uzalezniamy sie od tablicy zarzadzanej przez obiekt zewnetrzny
	this->arr = new char[length + 1]; // Marek

	//skopiowac input -> arr, na koncu dopisac 0
	//memcpy, strcpy - z ANSI C; albo petla for
	for (int i = 0; i < length; i++)
		arr[i] = input[i];
	arr[length] = '\0';
}

MyString::MyString(const MyString& other) // Marek
{
	int length = std::strlen(other.arr);
	this->arr = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->arr[i] = other.arr[i];
	}
	this->arr[length] = '\0';
}

MyString& MyString::operator=(MyString other) // Marek
{
	this->arr = new char[std::strlen(other.arr) + 1];
	for (int i = 0; i < std::strlen(other.arr); i++)
	{
		//*(arr + i) = *(other.arr + 1); // unikamy tego zapisu
		this->arr[i] = other.arr[i];
	}
	this->arr[std::strlen(other.arr)] = '\0';
	return *this; // Marek
}

MyString::~MyString()
{
	delete[] arr;
}

void MyString::print()
{
	std::cout << arr << std::endl;
}

MyString MyString::append(char* input)
{
	int length1 = std::strlen(arr); //zlicza dugo pierwszej tablicy - 3
	int length2 = std::strlen(input); // zlicza dugo drugiej tablicy - 3
	int length3 = length1 + length2;// dodaje te dugoci - 6
	char* newArr = new char[length3 + 1]; // tworzymy nowego stringa - dodajemy do dugoci +1 dla zera - 7
	for (int i = 0; i < length1; i++) //wypeniamy znakami z pierwszej tablicy
	{
		newArr[i] = arr[i]; // [a,l,a]
	}
	for (int i = 0; i < length2; i++) //wypeniamy znakami z drugiej tablicy
	{
		newArr[i + length1] = input[i];// [a,l,a, k, o, t]
	}
	newArr[length3] = '\0'; //ustawia ostatnie miejsce w tablicy na zero
	return MyString(newArr);
}
