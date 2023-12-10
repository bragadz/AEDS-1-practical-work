#ifndef DATA_H
#define DATA_H

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d = 0, int m = 0, int a = 0);
    void lerData();
    void escreverData() const;
    bool mesAniversario(int mesComparar) const;
};

#endif