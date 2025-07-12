#include <iostream>
using namespace std;

int main() {
    int n; // quantidade de bombas
    int bomb; // posição da bomba a ser lida dentro do laço (ele executa uma ação por vez, então basta uma variável)
    int pos = 5; // posição inicial do personagem
    bool buuuuummmm = false; // identifica se o personagem foi atingido por uma bomba

    // lê a quantidade de bombas e entra em um laço para processar cada uma das bombas.
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> bomb;
        // se a bomba estiver à esquerda do personagem (bomb < pos) e ele ainda não estiver no seu limite
        // à direita (pos < 10), então ele se move para a direita.
        if (bomb < pos && pos < 10) {
            pos++;
        }
        // se a bomba estiver à direita do personagem (bomb > pos) e ele ainda não estiver no seu limite
        // à esquerda (pos > 0), então ele se move para a direita.
        else if (bomb > pos && pos > 0) {
            pos--;
        }
        // se a bomba estiver na mesma posição do personagem (bomb == pos), então "buuuuummmm". Já era!
        else if (bomb == pos) {
            buuuuummmm = true;
            break; // se foi atingido, não precisa continuar o laço: já morreu mesmo.
        }
    }
    // envia o resultado para a saída.
    if (buuuuummmm) {
        cout << "Game Over" << endl;
    }
    else {
        cout << pos << endl;
    }
    
    return 0;
}
