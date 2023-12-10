#include "Aluno.h"
#include "Professor.h"
#include "Pessoa.h"
#include <iostream>
#include <string>
#include <limits>
#include <new>

using namespace std;

void listarAlunos(const Aluno *alunos, int tamanho)
{
    cout << "\n--- Listagem de Alunos ---\n";
    for (int i = 0; i < tamanho; ++i)
    {
        alunos[i].escreverAluno();
        cout << "------------------------------------\n";
    }
}

void listarProfessores(const Professor *professores, int tamanho)
{
    cout << "\n--- Listagem de Professores ---\n";
    for (int i = 0; i < tamanho; ++i)
    {
        professores[i].escreverProfessor();
        cout << "------------------------------------\n";
    }
}

void listarAniversariantes(const Pessoa *pessoas, int tamanho, int mes)
{
    cout << "\n--- Listagem de Aniversariantes do Mes ---\n";
    for (int i = 0; i < tamanho; ++i)
    {
        if (pessoas[i].mesAniversario(mes))
        {
            pessoas[i].escreverPessoa();
            cout << "------------------------------------\n";
        }
    }
}

int mostrarMenu()
{
    int escolha;

    cout << "\n--- Menu ---\n";
    cout << "0 - Sair\n";
    cout << "1 - Cadastrar aluno\n";
    cout << "2 - Cadastrar professor\n";
    cout << "3 - Listar alunos\n";
    cout << "4 - Listar professores\n";
    cout << "5 - Listar aniversariantes do mes\n";
    cout << "Escolha uma opcao: " << endl;

    // Verifica se a entrada e valida (um numero inteiro)
    while (!(cin >> escolha) || escolha < 0 || escolha > 5)
    {
        cin.clear();                                         // Limpa a flag de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada invalida
        cout << "Opcao invalida. Escolha novamente: ";
    }

    cin.ignore(); // Limpar o buffer do teclado

    return escolha;
}