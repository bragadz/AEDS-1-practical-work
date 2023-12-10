#include "Pessoa.h"
#include <iostream>
#include <string>
#include <limits>
#include <new>

using namespace std;

Pessoa::Pessoa(const string &n, int d, int m, int a) : nome(n), dataNascimento(d, m, a) {}

void Pessoa::setNome(const string &n) { nome = n; }

string Pessoa::getNome() const { return nome; }

void Pessoa::escreverPessoa() const
{
    escreverNome();
    cout << "\nData de Nascimento: ";
    dataNascimento.escreverData();
}

void Pessoa::escreverNome() const
{
    cout << "Nome: " << nome << endl;
}

bool Pessoa::mesAniversario(int mesComparar) const
{
    return dataNascimento.mesAniversario(mesComparar);
}

void Pessoa::lerNome()
{
    cout << "Digite o nome: ";
    getline(cin, nome);
}