#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

using namespace std;

class Aluno : public Pessoa
{
private:
    int matricula;
    static int quantidadeAlunos;

public:
    Aluno(const string &n = "", int d = 0, int m = 0, int a = 0, int mat = 0);
    static int getQuantidadeAlunos();
    void escreverAluno() const;
};

#endif