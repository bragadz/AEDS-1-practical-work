#include "Professor.h"
#include <iostream>
#include <string>
#include <limits>
#include <new>

using namespace std;

int Professor::quantidadeProfessores = 0;

Professor::Professor(const string &n, int d, int m, int a, const string &tit) : Pessoa(n, d, m, a), titulacao(tit)
{
    quantidadeProfessores++;
}

int Professor::getQuantidadeProfessores()
{
    return quantidadeProfessores;
}

void Professor::escreverProfessor() const
{
    escreverPessoa();
    cout << "Titulacao: " << titulacao << endl;
}