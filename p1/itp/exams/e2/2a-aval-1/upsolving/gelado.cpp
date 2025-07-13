#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

// TODO: Problema com a sintaxe aboradado no problema (y, x) e (x, y) qual a usada no plano cartesiano?

// --- Testes ---
// Você pode definir novos testes para a sua função aqui

struct Terreno {
    int profundidade;
    int largura;
    int alturas[500][500];
    bool congelado[500][500];
};

struct Posicao {
    int x;
    int y;
};


void congelar_terreno(Terreno& mapa, Posicao posicao){
  if(posicao.x < 0 || posicao.x > mapa.largura - 1 || posicao.y < 0 || posicao.y > mapa.profundidade - 1){
    return;
  }

  if(mapa.congelado[posicao.y][posicao.x]) {
    return;
  }

  if(mapa.alturas[posicao.y][posicao.x] >= 0){
    mapa.congelado[posicao.y][posicao.x] = true;
    congelar_terreno(mapa, Posicao { posicao.x+1, posicao.y} );
    congelar_terreno(mapa, Posicao { posicao.x-1, posicao.y} );
    congelar_terreno(mapa, Posicao { posicao.x, posicao.y+1} );
    congelar_terreno(mapa, Posicao { posicao.x, posicao.y-1} );
  }

  return;
}

bool congelado(Terreno& mapa, Posicao posicao_rei, Posicao posicao_jogador){
    for (int i = 0; i < mapa.profundidade; i++)
    {
      for (int k = 0; k < mapa.largura; k++)
      {
        mapa.congelado[i][k] = false;
      }
    }

    congelar_terreno(mapa, posicao_rei);
    return mapa.congelado[posicao_jogador.y][posicao_jogador.x];
}

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

  Posicao rei{ 3, 1 };
  CHECK(congelado(t1, rei, Posicao{ 0, 3}) == true); // Jogador na ilha do Rei Gelado
  CHECK(congelado(t1, rei, Posicao{ 0, 0 }) == false); // Jogador no mar
  CHECK(congelado(t2, rei, Posicao{ 4, 0 }) == true); // Jogador na ilha do Rei Gelado
  CHECK(congelado(t2, rei, Posicao{ 4, 3 }) == false); // Jogador na ilha inferior
}