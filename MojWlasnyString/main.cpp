#include <iostream>
#include "MyString.hpp"

int main()
{
    MyString empty;
    empty.print();

    MyString alaMaKota((char*)"Ala ma kota");
    alaMaKota.print();
    MyString alaMaKotaAKotMa = alaMaKota.append((char*)",a kot ma ");
    alaMaKota.print();
    alaMaKotaAKotMa.print();

    char arr[] = {"A, l, e"};
    MyString ale(arr);
    ale.print(); //Ale
    MyString full = alaMaKotaAKotMa.append(ale);
    full.print(); //Ala ma kota a kot ma Ale
}


