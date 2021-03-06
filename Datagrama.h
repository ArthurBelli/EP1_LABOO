#ifndef DATAGRAMA_H
#define DATAGRAMA_H
#include <string>

using namespace std;

class Datagrama {
private:
    int origem;
    int destino;
    int ttl;
    string dado;

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
