#include <iostream>
using namespace std;

int main() {
    int n;  // quantidade de bombas
    int action; // ação do personagem a ser lida dentro do laço (ele executa uma ação por vez, então basta uma variável)
    int pos = 5; // posição inicial do personagem
    bool buuuuummmm = false; // identifica se o personagem foi atingido por uma bomba

    // lê a quantidade de bombas e as posições das bombas
    cin >> n;
    int bombs[n];
    for(int i = 0; i < n; i++) {
        cin >> bombs[i];
    }

    // percorre todas as bombas, realizando uma ação por vez.
    for(int i = 0; i < n; i++) {
        // testa inicialmente se o personagem foi atingido por uma bomba
        if (bombs[i] == pos) {
            buuuuummmm = true;
            break;  // se foi atingido, não precisa continuar o laço: já morreu!
        }
        // lê a ação do personagem
        cin >> action;

        // 1) se for -1, move o personagem para a esquerda (se possível);
        if (action == -1 && pos > 0) {
            pos--;
        }
        // 2) se for 1, move o personagem para a direita (se possível);
        else if (action == 1 && pos < 10) {
            pos++;
        }
        // 3) se for 0, remove a próxima bomba da posição atual do personagem que ainda não caiu (se houver
        //    alguma bomba nessa posição);
        else if (action == 0) {
            for(int b = i + 1; b < n; b++) { // o b começa em i + 1 porque serão testadas as bombas que ainda não caíram
                if (bombs[b] == pos) {  // se houver uma bomba na posição atual do personagem
                    bombs[b] = -1;      // remove a bomba da posição atual do personagem (-1 é uma posição que o personagem
                    break;              // nunca irá chegar).
                }
            }
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