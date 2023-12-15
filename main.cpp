#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstring>

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a) {}

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }

    bool dataValida() const
    {
        return (dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12);
    }

    void setValores(int d, int m, int a)
    {
        setDia(d);
        setMes(m);
        setAno(a);
    }

    void lerData()
    {
        cout << "Digite o dia: ";
        cin >> dia;

        while (dia < 1 || dia > 31)
        {
            cout << "Dia invalido. Digite novamente: ";
            cin >> dia;
        }

        do
        {
            cout << "Digite o mes: ";
            cin >> mes;

            if (mes < 1 || mes > 12)
            {
                cout << "Mes invalido. Digite novamente.\n";
            }
        } while (mes < 1 || mes > 12);

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
private:
    string nome;
    Data dataNascimento;

public:
    virtual ~Pessoa() {}

    Pessoa(const string &n = "", const Data &data = Data()) : nome(n), dataNascimento(data) {}

    void setNome(const string &n)
    {
        nome = n;
    }

    string getNome() const
    {
        return nome;
    }

    virtual void escreverPessoa() const
    {
        escreverNome();
        cout << "Data de Nascimento: ";
        dataNascimento.escreverData();
    }

    void escreverNome() const
    {
        cout << "Nome: " << nome << endl;
    }

    void lerNome()
    {
        cout << "Digite o nome: ";
        getline(cin, nome);
    }

    void lerDataNascimento()
    {
        dataNascimento.lerData();
    }

    int getDiaNascimento() const
    {
        return dataNascimento.getDia();
    }

    int getMesNascimento() const
    {
        return dataNascimento.getMes();
    }

    int getAnoNascimento() const
    {
        return dataNascimento.getAno();
    }

    void levarValorNome(const string &n)
    {
        setNome(n);
    }

    string recuperarValorNome() const
    {
        return getNome();
    }

    void lerNomeTeclado()
    {
        lerNome();
    }

    void escreverNomeTela() const
    {
        escreverNome();
    }

    void lerPessoaTeclado()
    {
        lerNome();
        lerDataNascimento();
    }

    void escreverPessoaTela() const
    {
        escreverPessoa();
    }

    virtual string getTipo() const = 0;
    virtual void escreverDetalhes() const = 0;
};

class Aluno : public Pessoa
{
private:
    int matricula;
    static int quantidadeAlunos;

public:
    Aluno(const string &n = "", int d = 0, int m = 0, int a = 0, int mat = 0) : Pessoa(n, Data(d, m, a)), matricula(mat)
    {
        quantidadeAlunos++;
    }

    static int getQuantidadeAlunos()
    {
        return quantidadeAlunos;
    }

    void escreverAluno() const
    {
        escreverNome();
        cout << "Data de Nascimento: " << getDiaNascimento() << "/" << getMesNascimento() << "/" << getAnoNascimento() << endl;
        cout << "Matricula: " << matricula << endl;
    }

    string getTipo() const override
    {
        return "Aluno";
    }

    int getMatricula() const
    {
        return matricula;
    }

    void escreverDetalhes() const override
    {
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
    Professor(const string &n = "", int d = 0, int m = 0, int a = 0, const string &tit = "") : Pessoa(n, Data(d, m, a)), titulacao(tit)
    {
        quantidadeProfessores++;
    }

    static int getQuantidadeProfessores()
    {
        return quantidadeProfessores;
    }

    string getTitulacao() const
    {
        return titulacao;
    }

    void escreverProfessor() const
    {
        escreverNome();
        cout << "Data de Nascimento: " << getDiaNascimento() << "/" << getMesNascimento() << "/" << getAnoNascimento() << endl;
        cout << "Titulacao: " << titulacao << endl;
    }

    string getTipo() const override
    {
        return "Professor";
    }

    void escreverDetalhes() const override
    {
        cout << "Titulacao: " << titulacao << endl;
    }
};

int Professor::quantidadeProfessores = 0;

void salvarDados(const Pessoa *const pessoas[], int tamanho, const string &nomeArquivo);
void carregarDados(Pessoa *pessoas[], int &quantidadePessoas, const string &nomeArquivo);

void listarAlunos(const Pessoa *const pessoas[], int tamanho)
{
    cout << "\n--- Listagem de Alunos ---\n";
    bool alunosCadastrados = false;

    for (int i = 0; i < tamanho; ++i)
    {
        const Aluno *aluno = dynamic_cast<const Aluno *>(pessoas[i]);

        if (aluno)
        {
            alunosCadastrados = true;
            aluno->escreverPessoa();
            aluno->escreverDetalhes();
            cout << "------------------------------------\n";
        }
    }

    if (!alunosCadastrados)
    {
        cout << "Nenhum aluno cadastrado.\n";
    }
}

void listarProfessores(const Pessoa *const pessoas[], int tamanho)
{
    cout << "\n--- Listagem de Professores ---\n";

    for (int i = 0; i < tamanho; ++i)
    {
        const Professor *professor = dynamic_cast<const Professor *>(pessoas[i]);

        if (professor)
        {
            professor->escreverPessoa();
            professor->escreverDetalhes();
            cout << "------------------------------------\n";
        }
    }

    if (Professor::getQuantidadeProfessores() == 0)
    {
        cout << "Nenhum professor cadastrado.\n";
    }
}

void listarAniversariantes(const Pessoa *const pessoas[], int tamanho, int mes)
{
    cout << "\n--- Listagem de Aniversariantes do Mes ---\n";
    for (int i = 0; i < tamanho; ++i)
    {
        if (pessoas[i]->getMesNascimento() == mes)
        {
            cout << "Tipo: " << pessoas[i]->getTipo() << endl;
            pessoas[i]->escreverPessoa();
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

    while (!(cin >> escolha) || escolha < 0 || escolha > 5)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcao invalida. Escolha novamente: ";
    }

    cin.ignore();

    return escolha;
}

void salvarDados(const Pessoa *const pessoas[], int tamanho, const string &nomeArquivo)
{
    ofstream arquivo(nomeArquivo, ios::out);

    if (arquivo.is_open())
    {
        for (int i = 0; i < tamanho; ++i)
        {
            arquivo << pessoas[i]->getTipo() << " ";
            arquivo << pessoas[i]->recuperarValorNome() << " ";
            arquivo << pessoas[i]->getDiaNascimento() << " ";
            arquivo << pessoas[i]->getMesNascimento() << " ";
            arquivo << pessoas[i]->getAnoNascimento() << " ";

            // Se for um Aluno, salvar a matrícula
            if (pessoas[i]->getTipo() == "Aluno")
            {
                arquivo << dynamic_cast<const Aluno *>(pessoas[i])->getMatricula() << " ";
            }
            // Se for um Professor, salvar a titulação
            else if (pessoas[i]->getTipo() == "Professor")
            {
                arquivo << dynamic_cast<const Professor *>(pessoas[i])->getTitulacao() << " ";
            }

            arquivo << endl;
        }

        arquivo.close();
        cout << "Dados salvos com sucesso.\n";
    }
    else
    {
        cerr << "Não foi possível abrir o arquivo para salvar os dados.\n";
    }
}

void carregarDados(Pessoa *pessoas[], int &quantidadePessoas, const string &nomeArquivo)
{
    ifstream arquivo(nomeArquivo, ios::in);

    if (arquivo.is_open())
    {
        while (arquivo >> ws) // Pular espaços em branco
        {
            string tipo;
            string nome;
            int dia, mes, ano;

            arquivo >> tipo >> nome >> dia >> mes >> ano;

            // Se for um Aluno, carregar a matrícula
            if (tipo == "Aluno")
            {
                int matricula;
                arquivo >> matricula;
                pessoas[quantidadePessoas++] = new Aluno(nome, dia, mes, ano, matricula);
            }
            // Se for um Professor, carregar a titulação
            else if (tipo == "Professor")
            {
                string titulacao;
                arquivo >> titulacao;
                pessoas[quantidadePessoas++] = new Professor(nome, dia, mes, ano, titulacao);
            }
        }

        arquivo.close();
        cout << "Dados carregados com sucesso.\n";
    }
    else
    {
        cerr << "Não foi possível abrir o arquivo para carregar os dados.\n";
    }
}

int main()
{
    const int capacidadeMaxima = 100;
    Pessoa *pessoas[capacidadeMaxima];

    int quantidadePessoas = 0;

    carregarDados(pessoas, quantidadePessoas, "dados.dat");

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
                if (Aluno::getQuantidadeAlunos() < capacidadeMaxima)
                {
                    Aluno novoAluno;
                    novoAluno.lerNomeTeclado();
                    novoAluno.lerDataNascimento();
                    int matricula;

                    cout << "Digite a matricula do aluno: ";
                    cin >> matricula;

                    pessoas[quantidadePessoas++] = new Aluno(novoAluno.recuperarValorNome(), novoAluno.getDiaNascimento(), novoAluno.getMesNascimento(), novoAluno.getAnoNascimento(), matricula);
                }
                else
                {
                    throw bad_alloc();
                }
                break;

            case 2:
                if (Professor::getQuantidadeProfessores() < capacidadeMaxima)
                {
                    Professor novoProfessor;
                    novoProfessor.lerNomeTeclado();
                    novoProfessor.lerDataNascimento();
                    string titulacao;

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

                    pessoas[quantidadePessoas++] = new Professor(novoProfessor.recuperarValorNome(), novoProfessor.getDiaNascimento(), novoProfessor.getMesNascimento(), novoProfessor.getAnoNascimento(), titulacao);
                }
                else
                {
                    throw bad_alloc();
                }
                break;

            case 3:
                if (quantidadePessoas > 0)
                {
                    listarAlunos(pessoas, quantidadePessoas);
                }
                else
                {
                    cout << "Nenhum aluno cadastrado.\n";
                }
                break;
            case 4:
                if (Professor::getQuantidadeProfessores() > 0)
                {
                    listarProfessores(pessoas, quantidadePessoas);
                }
                else
                {
                    cout << "Nenhum professor cadastrado.\n";
                }
                break;
            case 5:
            {
                int mes;
                cout << "Digite o mes para listar os aniversariantes: ";
                cin >> mes;

                listarAniversariantes(pessoas, quantidadePessoas, mes);
                break;
            }
            default:
                cout << "Opcao invalida.\n";
                break;
            }
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

    // Salvar dados ao encerrar o programa
    salvarDados(pessoas, quantidadePessoas, "dados.dat");

    // Liberar memória
    for (int i = 0; i < quantidadePessoas; ++i)
    {
        delete pessoas[i];
    }

    return 0;
}