#ifndef DATAGRAMA_H
#define DATAGRAMA_H

class Datagrama(int origem, int destino, int ttl, string dado) {
private:
    int origem;
    int destino;
    int Ttl;
    string dado;
    //incluir se faltar alguma coisa
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
}


#endif // DATAGRAMA_H
