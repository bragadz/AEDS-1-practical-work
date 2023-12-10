#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include "Aluno.h"
#include "Professor.h"
#include "Pessoa.h"

// Declarações das funções
void listarAlunos(const Aluno* alunos, int quantidade);
void listarProfessores(const Professor* professores, int quantidade);
void listarAniversariantes(const Pessoa* pessoas, int total, int mes);
int mostrarMenu();

#endif