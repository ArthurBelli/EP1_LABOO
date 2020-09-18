#include "TabelaDeRepasse.h"
#include "Roteador.h"
#define MAXIMO_TABELA 5
#include <iostream>

using namespace std;
class Roteador;

TabelaDeRepasse::TabelaDeRepasse() {
    vetRot = new Roteador*[MAXIMO_TABELA];
    vetEnd = new int[MAXIMO_TABELA];
    rotPadrao = NULL;
    int i;
    for (i = 0; i < MAXIMO_TABELA; i++) {
        vetRot[i] = NULL;
        vetEnd[i] = 0;
    } // vetores ao serem criados ficam [NULL, NULL, NULL, ...] e [0,0,0,..]
}

TabelaDeRepasse::~TabelaDeRepasse() {
    delete[] vetRot;
    delete[] vetEnd;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente) {
    int i = 0;
    while (vetRot[i] != NULL && vetEnd[i] != 0) {
        i++;
        if (i == MAXIMO_TABELA) {
            cout << "Erro no mapeamento: tabela cheia" << endl;
            return false;
        }
    }
    if ((vetRot[i] == NULL && vetEnd != 0) || (vetRot[i] != NULL && vetEnd == 0)) {
        cout << "Erro no mapeamento: vetores desalinhados" << endl;
        return false;
    } else {
        vetRot[i] = adjacente;
        vetEnd[i] = endereco;
        return true;
    }
}

Roteador** TabelaDeRepasse::getAdjacentes() {
    //falta alguma coisa aqui?
    Roteador** adjacentes;
    int i;
    int quantAdj = this->getQuantidadeDeAdjacentes();
    adjacentes = new Roteador*[quantAdj];
    for (i = 0; i < quantAdj; i++) adjacentes[i] = vetRot[i];
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    int contOcupado,i; //contador de quantas casas ocupadas tem no vetor
    contOcupado = 0;
    for (i = 0; i < MAXIMO_TABELA; i++) {
        if (vetRot[i] != NULL) contOcupado++;
    }
    return contOcupado;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao) {
    rotPadrao = padrao;
}

Roteador* TabelaDeRepasse::getDestino(int endereco) {
    int i;
    for (i = 0; i < MAXIMO_TABELA && endereco != vetEnd[i]; i++);
    if(i == MAXIMO_TABELA) return rotPadrao;
    else return vetRot[i];
}

void TabelaDeRepasse::imprimir() {
    //implementar
}
