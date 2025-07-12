/*
"No reino tão-tão distante, havia um rei tão frio, mas tão frio, que tudo que tocava congelava...
e tudo que tocava o que tocava também congelava. Assim, o mundo só não vivia uma era glacial, onde
tudo estaria congelado, porque o reino ficava numa ilha" (bem... e o mar salgado não congelava).

Assim começa o enredo do jogo "Gelado", que você foi convidado a fazer parte da equipe de
desenvolvimento. Sua primeira tarefa é implementar uma função para verificar se o jogador
se encontra na fatídica ilha do "Rei Gelado" (Não! Não é o mesmo da Hora de Aventura! Outro cara
pegou a coroa de Evergreen ;-)).

Defina um tipo chamado Posicao, que representa uma posição no terreno, com dois atributos do
tipo inteiro: linha e coluna. Defina também um novo tipo chamado Terreno, similar ao da atividade
"Terreno", mas que deve conter um atributo adicional: uma matriz de booleanos com as mesmas
dimensões do terreno, representando se cada ponto do terreno está congelado ou não.

Em seguida, implemente uma função que recebe como parâmetro um terreno (mesmo tipo definido na
atividade "Terreno") e duas posições (a do rei e a do jogador), e retorna um booleano indicando
se o jogador está na ilha do Rei Gelado.

Neste jogo, uma ilha é definida por pontos vizinhos que têm altitude maior ou igual a 0.
Ou seja, onde houver valores negativos, é mar. Outro detalhe do jogo é que o gelo do Rei Gelado
só se espalha nas direções ortogonais (cima, baixo, esquerda e direita). Ou seja, ele não se
espalha nas diagonais.

Para ficar mais claro, considere o terreno a seguir e que o rei esteja na posição (1, 3), na posição
de altitude 2.

```
-1  0  1  2  3
-3 -1  0  2  5
 0  1  2  3  4
 1 -1  0  1  2
```

Nesse terreno, há apenas uma ilha, pois todos os pontos com altitude maior ou igual a 0 estão
conectados. Como há apenas uma ilha e o rei se encontra na ilha, então todos os pontos da ilha vão
estar congelados. Assim, se o jogador estiver na posição (3, 0), a função deve retornar true,
pois o jogador está na ilha do Rei Gelado. Porém, se o jogador estiver na posição (0, 0), a função
deve retornar false, pois o jogador está no mar.

Outro exemplo. Considere o seguinte terreno e o rei ainda na posição (1, 3).
```
-1  0  1  2  3
-3 -1  0  2  0
-2 -1 -1 -1 -1
-2 -1 -2  1  2
```

Neste caso, o terreno tem duas ilhas: uma na parte superior (com os pontos (0, 1), (0, 2), (0, 3),
(0, 4), (1, 2), (1, 3) e (1, 4)) e outra na parte inferior (com os pontos (3, 3) e (3, 4)). Se o
jogador estiver na posição (0, 4), a função deve retornar true, pois o jogador está na mesma ilha
do Rei Gelado. Porém, se o jogador estiver na posição (3, 4), a função deve retornar false,
pois o jogador está na ilha inferior, que não é a do Rei Gelado.

DICA: Você pode até tentar resolver o problema sem usar recursão, mas a solução mais simples é
criar uma função recursiva para "congelar" as posições da ilha do rei. Você faz isso congelando
recursivamente, a partir da posição do rei, as posições vizinhas (cima, baixo, esquerda e direita)
que ainda não foram congeladas e que não são mar. Depois, basta verificar se a posição do jogador
está congelada.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

// Uma posição no terreno é representada por uma linha e uma coluna
struct Posicao {
    int linha, coluna;
};

// Mesmo tipo definido na atividade "Terreno", mas com um atributo adicional
// para indicar quando um ponto está congelado ou não.
struct Terreno {
    int profundidade; // número de linhas
    int largura;      // e de colunas da matriz
    int altitudes[500][500];
    bool congelado[500][500]; // mtriz para indicar se o ponto está congelado
};

// Essa é a função recursiva, chave do problema, que "congela" as posições vizinhas
// a partir de uma posição inicial (linha, coluna).
void congelar(Terreno &terreno, int linha, int coluna) {
    // 1º caso base: se a posição está fora dos limites do terreno, nada a fazer
    if (linha < 0 || linha >= terreno.profundidade || coluna < 0 || coluna >= terreno.largura) {
        return;
    }
    // 2º caso base: se a posição já está congelada ou é mar, nada a fazer
    if (terreno.congelado[linha][coluna] || terreno.altitudes[linha][coluna] < 0) {
        return;
    }
    
    // Marca o ponto como congelado
    terreno.congelado[linha][coluna] = true;

    // Agora... a parte recursiva!
    // Congela recursivamente as posições vizinhas (cima, baixo, esquerda e direita)
    congelar(terreno, linha - 1, coluna); // Cima
    congelar(terreno, linha + 1, coluna); // Baixo
    congelar(terreno, linha, coluna - 1); // Esquerda
    congelar(terreno, linha, coluna + 1); // Direita
}

bool congelado(Terreno &terreno, const Posicao &rei, const Posicao &jogador) {
    // Antes de começar a congelar, precisamos garantir que a matriz de congelamento
    // esteja limpa (ou seja, que nenhum ponto esteja congelado).
    for (int i = 0; i < terreno.profundidade; ++i) {
        for (int j = 0; j < terreno.largura; ++j) {
            terreno.congelado[i][j] = false; // Inicializa a matriz de congelamento
        }
    }
    // Agora, sim, podemos congelar a ilha a partir da posição do rei
    congelar(terreno, rei.linha, rei.coluna);

    // Depois de tudo congelado, retornamos o estado de congelamento da posição do jogador
    return terreno.congelado[jogador.linha][jogador.coluna];
}

// --- Testes ---
// Você pode definir novos testes para a sua função aqui

// Mas esta parte não pode ser alterada!
TEST_CASE("Testa a senha formada por um terreno e uma chave de decodificação") {
  Terreno t1 = { 4, 5, {
    { -1,  0,  1,  2,  3 },
    { -3, -1,  0,  2,  5 },
    {  0,  1,  2,  3,  4 },
    {  1, -1,  0,  1,  2 }
  }};
  Terreno t2 = { 4, 5, {
    { -1,  0,  1,  2,  3 },
    { -3, -1,  0,  1,  0 },
    { -2, -1, -1, -1, -1 },
    { -2, -1, -2,  1,  2 }
  }};
  Posicao rei{ 1, 3 };
  CHECK(congelado(t1, rei, Posicao{ 3, 0 }) == true); // Jogador na ilha do Rei Gelado
  CHECK(congelado(t1, rei, Posicao{ 0, 0 }) == false); // Jogador no mar
  CHECK(congelado(t2, rei, Posicao{ 0, 4 }) == true); // Jogador na ilha do Rei Gelado
  CHECK(congelado(t2, rei, Posicao{ 3, 4 }) == false); // Jogador na ilha inferior
}