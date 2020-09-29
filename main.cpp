#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Roteador.h"
#include "Rede.h"
#include <iostream>
#include <string>

#define QUANTIDADE_DE_ROTEADORES 6

using namespace std;

void Menu0(int &opcao);
void Menu1(int &origem, int &destino, int &ttl, string &mensagem);
void Menu2(int &tempo);
void MenuFim(int &opcao);

int main() {
    /*setup da rede, dos roteadores e da tabela*/
    Roteador** vetRot = new Roteador*[QUANTIDADE_DE_ROTEADORES];
    /*roteador, posicao no vetor e tabela do r1*/
    Roteador* r1 = new Roteador(1);
    vetRot[0] = r1;
    /*roteador, posicao no vetor e tabela do r2*/
    Roteador* r2 = new Roteador(2);
    vetRot[1] = r2;
    /*roteador, posicao no vetor e tabela do r3*/
    Roteador* r3 = new Roteador(3);
    vetRot[2] = r3;
    /*roteador, posicao no vetor e tabela do r4*/
    Roteador* r4 = new Roteador(4);
    vetRot[3] = r4;
    /*roteador, posicao no vetor e tabela do r5*/
    Roteador* r5 = new Roteador(5);
    vetRot[4] = r5;
    /*roteador, posicao no vetor e tabela do r6*/
    Roteador* r6 = new Roteador(6);
    vetRot[5] = r6;

    /*mapeamento das tabelas*/
    r1->getTabela()->mapear(4,r4);
    r1->getTabela()->setPadrao(r2);

    r2->getTabela()->mapear(1,r1);
    r2->getTabela()->mapear(3,r3);
    r2->getTabela()->setPadrao(r5);

    r3->getTabela()->mapear(6,r6);
    r3->getTabela()->setPadrao(r2);

    r4->getTabela()->mapear(1,r1);
    r4->getTabela()->setPadrao(r5);

    r5->getTabela()->mapear(4,r4);
    r5->getTabela()->mapear(6,r6);
    r5->getTabela()->setPadrao(r2);

    r6->getTabela()->mapear(3,r3);
    r6->getTabela()->setPadrao(r5);

    Rede* rede = new Rede(vetRot, QUANTIDADE_DE_ROTEADORES);


    int opcao=0;
    while (opcao != 3) {
        if (opcao == 0) Menu0(opcao);
        if (opcao == 1) {
            int origem, destino, ttl;
            string mensagem;
            Menu1(origem, destino, ttl, mensagem);
            if (rede->getRoteador(origem) == NULL) {
                cout << "Erro: origem desconhecida" << endl;
            } else rede->enviar(mensagem, vetRot[origem-1], destino, ttl);
        } else if (opcao == 2) {
            int tempo;
            Menu2(tempo);
            for (int i = 1; i <= tempo; i++) {
                cout << "Instante " << i << endl;
                cout << "---" << endl;
                rede->passarTempo();
                cout << endl;
            }
        }
        MenuFim(opcao);
    }
    return 0;
}

void Menu0(int &opcao) {
    cout << "Simulador de Rede" << endl << "---" << endl << "1) Enviar um datagrama" << endl 
    << "2) Passar tempo" << endl << "3) Sair" << endl << "Esolha uma opcao: ";
    cin >> opcao;
}

void Menu1(int &origem, int &destino, int &ttl, string &mensagem) {
    cout << endl << "Endereco do roteador de origem: ";
    cin >> origem;
    cout << "Endereco de destino: ";
    cin >> destino;
    cout << "TTL: ";
    cin >> ttl;
    cout << "Mensagem: ";
    cin >> mensagem;
}

void Menu2(int &tempo) {
    cout << endl << "Quantidade de tempo: ";
    cin >> tempo;
    cout << endl;
}

void MenuFim(int &opcao) {
    if(opcao != 3) opcao = 0;
    cout << endl;
}
