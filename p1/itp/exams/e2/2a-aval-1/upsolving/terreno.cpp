#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// --- Testes ---
// Você pode definir novos testes para a sua função aqui

struct Terreno {
    int largura;
    int profundidade;
    int alturas[500][500];
};

int maior_altitude(Terreno terreno){
  int maior_altitude = terreno.alturas[0][0];

  for(int i = 0; i < terreno.largura; i++){
    for (int k = 0; k < terreno.profundidade; k++)
    {
      if(terreno.alturas[i][k] > maior_altitude){
        maior_altitude = terreno.alturas[i][k];
      }
    }
  }

  return maior_altitude;
}

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