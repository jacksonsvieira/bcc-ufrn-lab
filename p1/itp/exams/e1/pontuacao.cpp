#include <iostream>
using namespace std;

int main() {
    int n; // quantidade de bombas
    int bomb; // posição da bomba a ser lida dentro do laço (ele executa uma ação por vez, então basta uma variável)
    int pont = 0; // pontuação inicial do personagem. a pontuação vai acumulando os valores das bombas (somatório)

    // lê a quantidade de bombas e entra em um laço para processar cada uma delas.
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> bomb;
        // se a bomba for 1, o personagem ganha 10 pontos
        if (bomb == 1) {
            pont += 10;
        }
        // se a bomba for 2, o personagem ganha 50 pontos
        else if (bomb == 2) {
            pont += 50;
        }
        // se a bomba for 3, o personagem ganha 90 pontos
        // como apenas 3 valores são possíveis, não precisa usar o else if novamente.
        else {
            pont += 90;
        }
    }
    // envia o resultado para a saída.
    cout << pont;
    return 0;
}
