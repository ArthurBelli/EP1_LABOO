#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include "Roteador.h"

#define MAXIMO_TABELA 5

class Roteador;

class TabelaDeRepasse {
    private:
    Roteador** vetRot; //vetor de roteadores
    int* vetEnd; //vetor de endereços
    Roteador* rotPadrao;
    public:
        TabelaDeRepasse();
        ~TabelaDeRepasse();
        bool mapear(int endereco, Roteador* adjacente);
        Roteador** getAdjacentes();
        int getQuantidadeDeAdjacentes();
        void setPadrao(Roteador* padrao);
        Roteador* getDestino(int endereco);

        void imprimir();

};

#endif // TABELADEREPASSE_H
