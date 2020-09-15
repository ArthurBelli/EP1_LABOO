#ifndef ROTEADOR_H
#define ROTEADOR_H
#define TAMANHO_FILA 3
#include "TabelaDeRepasse.h"
#include "Datagrama.h"


class Roteador (int endereco) {
private:

public:
    Roteador(int endereco);
    ~Roteador();
    TabelaDeRepasse* getTabela();
    Fila* getFila();
    int getEndereco();
    void receber(Datagrama* d);
    void processar();
    string getUltimoDadoRecebido();
    void imprimir();
};

#endif // ROTEADOR_H
