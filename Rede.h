#ifndef REDE_H
#define REDE_H
#include "Roteador.h"


class Rede(Roteador** roteadores, int quantidadeDeRoteadores) {
private:

public:
    Rede(Roteador** roteadores, int quantidadeDeRoteadores);
    ~Rede();
    Roteador* getRoteador(int endereco);
    void enviar(string texto, Roteador* origem, int destino, int ttl);
    void passarTempo();

    void imprimir();
};

#endif // REDE_H
