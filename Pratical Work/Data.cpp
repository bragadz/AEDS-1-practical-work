#include "Data.h"
#include <iostream>
#include <string>
#include <limits>
#include <new>

using namespace std;

Data::Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

void Data::lerData()
{
    cout << "Digite o dia: ";
    cin >> dia;

    cout << "Digite o mes: ";
    cin >> mes;

    cout << "Digite o ano: ";
    cin >> ano;
}

void Data::escreverData() const
{
    cout << dia << "/" << mes << "/" << ano << endl;
}

bool Data::mesAniversario(int mesComparar) const
{
    return mes == mesComparar;
}