#pragma once
#include <iostream>
#include<string>

//immutable
class MyString
{
	char* arr;
public:
	MyString();
	MyString(char* input);
	void print();
	//albo zwraca nowy obiekt typu MyString
	void append(char* input); // to spełnia cechy immutability
	//albo append zmienia aktualny obiekt MyString
	//void append(char* input);
	void appendToSame(char* input);

	MyString append(MyString input);
	void appendToSame(MyString input);

	MyString firstWord();
};