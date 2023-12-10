#include <iostream>
#include <string>
#include <limits>
#include <new>

#include "Aluno.h"
#include "Professor.h"
#include "FuncoesAuxiliares.h"

using namespace std;

int main()
{
    const int capacidadeMaxima = 100;
    Aluno alunos[capacidadeMaxima];
    Professor professores[capacidadeMaxima];
    Pessoa pessoas[capacidadeMaxima];

    int quantidadeAlunos = 0;
    int quantidadeProfessores = 0;

    int escolha;

    do
    {
        escolha = mostrarMenu();

        try
        {

            switch (escolha)
            {
            case 0:
                cout << "Encerrando o programa.\n";
                break;
            case 1:
                if (quantidadeAlunos < capacidadeMaxima)
                {
                    alunos[quantidadeAlunos].lerNome();
                    int dia, mes, ano, matricula;

                    cout << "Digite o dia de nascimento: ";
                    cin >> dia;

                    cout << "Digite o mes de nascimento: ";
                    cin >> mes;

                    cout << "Digite o ano de nascimento: ";
                    cin >> ano;

                    cout << "Digite a matricula do aluno: ";
                    cin >> matricula;

                    alunos[quantidadeAlunos] = Aluno(alunos[quantidadeAlunos].getNome(), dia, mes, ano, matricula);
                    pessoas[quantidadeAlunos] = alunos[quantidadeAlunos];
                    quantidadeAlunos++;
                }
                else
                {
                    throw bad_alloc();
                }
                break;

            case 2:
                if (quantidadeProfessores < capacidadeMaxima)
                {
                    professores[quantidadeProfessores].lerNome();
                    int dia, mes, ano;
                    string titulacao;

                    cout << "Digite o dia de nascimento: ";
                    cin >> dia;

                    cout << "Digite o mes de nascimento: ";
                    cin >> mes;

                    cout << "Digite o ano de nascimento: ";
                    cin >> ano;

                    cout << "Escolha a titulacao do Professor:\n";
                    cout << "1 - Especialista\n";
                    cout << "2 - Mestre\n";
                    cout << "3 - Doutor\n";
                    cout << "Digite o numero correspondente a titulacao: ";

                    int opcaoTitulacao;
                    cin >> opcaoTitulacao;

                    while (opcaoTitulacao < 1 || opcaoTitulacao > 3)
                    {
                        cout << "Opcao invalida. Digite novamente (1 - Especialista, 2 - Mestre, 3 - Doutor): ";
                        cin >> opcaoTitulacao;
                    }

                    if (opcaoTitulacao == 1)
                    {
                        titulacao = "Especialista";
                    }
                    else if (opcaoTitulacao == 2)
                    {
                        titulacao = "Mestre";
                    }
                    else
                    {
                        titulacao = "Doutor";
                    }

                    professores[quantidadeProfessores] = Professor(professores[quantidadeProfessores].getNome(), dia, mes, ano, titulacao);
                    pessoas[quantidadeAlunos + quantidadeProfessores] = professores[quantidadeProfessores];
                    quantidadeProfessores++;
                }
                else
                {
                    throw bad_alloc();
                }
                break;

            case 3:
                if (quantidadeAlunos > 0)
                {
                    listarAlunos(alunos, quantidadeAlunos);
                }
                else
                {
                    cout << "Nenhum aluno cadastrado.\n";
                }
                break;
            case 4:
                if (quantidadeProfessores > 0)
                {
                    listarProfessores(professores, quantidadeProfessores);
                }
                else
                {
                    cout << "Nenhum professor cadastrado.\n";
                }
                break;
            case 5:
            {
                int mes;
                int total = quantidadeAlunos + quantidadeProfessores;
                cout << "Digite o mes para listar os aniversariantes: ";
                cin >> mes;

                listarAniversariantes(pessoas, total, mes);
                break;
            }
            default:
                cout << "Opcao invalida.\n";
                break;
            }

            // TRATAMENTO DE ERROS USANDO TRY E CATCH!!
        }
        catch (const bad_alloc &e)
        {
            cerr << "Erro de alocacao de memoria ao cadastrar aluno/professor: " << e.what() << endl;
        }
        catch (...)
        {
            cerr << "Ocorreu uma excecao nao identificada." << endl;
        }

    } while (escolha != 0);

    return 0;
}