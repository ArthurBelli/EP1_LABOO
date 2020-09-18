#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Roteador.h"
#include "Rede.h"

#include <iostream>
#include <string>

using namespace std;

void Menu1(int &opcao);


int main() {
    int opcao;
    Menu1(opcao);
    while (opcao != 3) {
        if (opcao == 1) {
            //magica 1
        } else {
            //magica 2
        }
    }
    return 0;
}

void Menu1(int &opcao) {
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Sair" << endl << "Esolha uma opcao: ";
    cin >> opcao;
}
