/*
Mapa de altitudes (ou de alturas) é uma forma de representar um terreno, onde cada ponto do mapa
possui uma altitude associada. Ele pode ser representado por uma matriz de inteiros, onde cada
elemento da matriz representa a altitude de um ponto específico do terreno. Por exemplo, na matriz
3x3 abaixo, cada número representa a altitude de um ponto do terreno:
```
1 2 3
4 5 6
7 8 9
```

Neste exemplo, o ponto (0, 0) tem altitude 1, o ponto (1, 1) tem altitude 5 e assim por diante.

Defina um novo tipo de dado, chamado Terreno, para representar um mapa de altitudes. O mapa deve
ter, além de suas altitudes, suas dimensões (profundidade e largura), e deve ter a capacidade de
representar terrenos com até 500x500 pontos.

Em seguida, escreva uma função que recebe um terreno e retorna a maior altitude presente nesse
terreno. Terrenos vazios devem retornar 0.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

// Terreno como um mapa de altitudes
struct Terreno {
    int profundidade; // número de linhas da matriz
    int largura;      // ... e o número de colunas
    int altitudes[500][500]; // matriz com as altitudes do terreno
};

// A função maior_altitude recebe um terreno e retorna a maior altitude presente nesse terreno.
// obs: o parâmetro terreno funciona também sem o "const" e "&", mas é mais eficiente como está abaixo.
int maior_altitude(const Terreno &terreno) {
    // caso do terreno vazio
    if (terreno.profundidade == 0 || terreno.largura == 0) {
        return 0; 
    }
    
    // percorre todos os pontos do terreno para encontrar a maior altitude
    int maior = terreno.altitudes[0][0];
    for (int i = 0; i < terreno.profundidade; ++i) {
        for (int j = 0; j < terreno.largura; ++j) {
            if (terreno.altitudes[i][j] > maior) {
                maior = terreno.altitudes[i][j];
            }
        }
    }
    return maior;
}

// --- Testes ---
// Você pode definir novos testes para a sua função aqui

// Mas esta parte não pode ser alterada!
TEST_CASE("Testa a maior altitude de vários tipos de terrenos") {
  Terreno t1 = {3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}; // Terreno 3x3
  Terreno t2 = {0, 0};                                    // Terreno vazio
  Terreno t3 = {2, 3, {{-1, -2, -3}, {-4, -5, -6}}};      // Terreno 2x3 com valores negativos
  Terreno t4 = {1, 1, {{42}}};                            // Terreno 1x1 com um único valor

  CHECK(maior_altitude(t1) == 9);
  CHECK(maior_altitude(t2) == 0); // Terreno vazio deve retornar 0  
  CHECK(maior_altitude(t3) == -1); // Terreno com valores negativos
  CHECK(maior_altitude(t4) == 42); // Terreno 1x1 deve retornar o único valor
}