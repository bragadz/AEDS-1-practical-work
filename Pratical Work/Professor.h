#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"

using namespace std;

class Professor : public Pessoa
{
private:
    string titulacao;
    static int quantidadeProfessores;

public:
    Professor(const string &n = "", int d = 0, int m = 0, int a = 0, const string &tit = "");
    static int getQuantidadeProfessores();
    void escreverProfessor() const;
};

#endif