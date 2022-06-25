#include "MyString.hpp"

MyString::MyString()
{
	this->arr = new char[1];
	this->arr[0] = '\0';
}

MyString::MyString(char* input)
{
	int length = std::strlen(input)+1;
	//this->arr = input; // unikamy - uzależniamy się od tablicy zarzadzanej przez 
	this->arr = new char[length];
	// strcpy(arr, input) - to też działa
	//skopiować input -> arr, na końcu dopisać 0
	//memcpy, strcpy - z ANSI C; albo pętla for
	// praca do wykoania
	for (int i = 0; i < length; i++)
	{
		arr[i] = input[i];
	}
	arr[length] = '\0';
}

void MyString::print()
{
	std::cout << arr;
	std::cout << std::endl;
}

MyString MyString::append(char* input)
{
	int length1 = std::strlen(arr); // zlicza długosc pierwszejm tablicy
	int length2 = std::strlen(input); // zlicza długość drugiej tablicy
	int length3 = length1 + length2 + 1; // dodaje tej dłguości +1, dla tego zera na końcu
	char* newArr = new char[length3 + 1]; // tworzymy nowego stringa 

	for (int i = 0; i < length1; i++) // wypełnimay znakami z pierwszej tablicy
	{
		newArr[i] = arr[i];
	}
	for (int i = 0; i < length3; i++) // wypełnimay znakami z drugiej tablicy
	{
		newArr[i + length1] = input[i];
	}
	newArr[length3] = '\0'; // ustawia ostatnie miejsce w tablicy na zero

	return MyString(newArr);

}

void MyString::appendToSame(char* input)
{

}

MyString MyString::append(MyString input)
{
	// arr ma dostęp 
	MyString result = append(input.arr);
	return result;
}
