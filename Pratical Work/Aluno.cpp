#include "Aluno.h"
#include <iostream>
#include <string>
#include <limits>
#include <new>

using namespace std;

int Aluno::quantidadeAlunos = 0;

Aluno::Aluno(const string &n, int d, int m, int a, int mat) : Pessoa(n, d, m, a), matricula(mat)
{
    quantidadeAlunos++;
}

int Aluno::getQuantidadeAlunos()
{
    return quantidadeAlunos;
}

void Aluno::escreverAluno() const
{
    escreverPessoa();
    cout << "Matricula: " << matricula << endl;
}