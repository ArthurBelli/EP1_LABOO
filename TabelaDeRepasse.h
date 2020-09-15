#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include "Roteador.h"


#define MAXIMO_TABELA 5
class TabelaDeRepasse(){
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
