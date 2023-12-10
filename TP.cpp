#include <iostream>
#include <string>
#include <limits>
#include <new>

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a) {}

    void lerData()
    {
        cout << "Digite o dia: ";
        cin >> dia;

        cout << "Digite o mes: ";
        cin >> mes;

        cout << "Digite o ano: ";
        cin >> ano;
    }

    void escreverData() const
    {
        cout << dia << "/" << mes << "/" << ano << endl;
    }

    bool mesAniversario(int mesComparar) const
    {
        return mes == mesComparar;
    }
};

class Pessoa
{
protected:
    string nome;
    Data dataNascimento;

public:
    Pessoa(const string &n = "", int d = 0, int m = 0, int a = 0) : nome(n), dataNascimento(d, m, a) {}

    void setNome(const string &n) { nome = n; }
    string getNome() const { return nome; }

    virtual void escreverPessoa() const
    {
        escreverNome();
        cout << "\nData de Nascimento: ";
        dataNascimento.escreverData();
    }

    void escreverNome() const
    {
        cout << "Nome: " << nome << endl;
    }

    bool mesAniversario(int mesComparar) const
    {
        return dataNascimento.mesAniversario(mesComparar);
    }

    void lerNome()
    {
        cout << "Digite o nome: ";
        getline(cin, nome);
    }
};

class Aluno : public Pessoa
{
private:
    int matricula;
    static int quantidadeAlunos;

public:
    Aluno(const string &n = "", int d = 0, int m = 0, int a = 0, int mat = 0) : Pessoa(n, d, m, a), matricula(mat)
    {
        quantidadeAlunos++;
    }

    static int getQuantidadeAlunos()
    {
        return quantidadeAlunos;
    }

    void escreverAluno() const
    {
        escreverPessoa();
        cout << "Matricula: " << matricula << endl;
    }
};

int Aluno::quantidadeAlunos = 0;

class Professor : public Pessoa
{
private:
    string titulacao;
    static int quantidadeProfessores;

public:
    Professor(const string &n = "", int d = 0, int m = 0, int a = 0, const string &tit = "") : Pessoa(n, d, m, a), titulacao(tit)
    {
        quantidadeProfessores++;
    }

    static int getQuantidadeProfessores()
    {
        return quantidadeProfessores;
    }

    void escreverProfessor() const
    {
        escreverPessoa();
        cout << "Titulacao: " << titulacao << endl;
    }
};

int Professor::quantidadeProfessores = 0;

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