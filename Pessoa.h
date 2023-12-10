#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "Data.h"

using namespace std;

class Pessoa
{
protected:
    string nome;
    Data dataNascimento;

public:
    Pessoa(const string &n = "", int d = 0, int m = 0, int a = 0);
    void setNome(const string &n);
    string getNome() const;
    virtual void escreverPessoa() const;
    void escreverNome() const;
    bool mesAniversario(int mesComparar) const;
    void lerNome();
};

#endif