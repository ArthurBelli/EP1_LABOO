#ifndef DATAGRAMA_H
#define DATAGRAMA_H
#include <string>

using namespace std;

class Datagrama {
private:
    int *origem = new int;
    int *destino = new int;
    int *ttl = new int;
    string *dado = new string;
    //incluir se julgar faltar alguma coisa
public:
    Datagrama(int origem, int destino, int ttl, string dado);
    ~Datagrama();
    int getOrigem();
    int getDestino();
    int getTtl();
    string getDado();
    void processar();

    bool ativo();
    void imprimir();
};


#endif // DATAGRAMA_H
