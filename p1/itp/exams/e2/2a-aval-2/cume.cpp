/*
Em uma das fases do jogo "Gelado", o Rei Gelado precisa ir para o ponto mais alto de sua ilha.
Porém, ele não tem uma visão completa do mapa, e só consegue ver apenas seus vizinhos imediatos
(cima, esquerda, direita e baixo).
Então, pra ele ir ao ponto mais alto, com sua visão limitada, ele adota a seguinte estratégia:
- se não houver nenhum vizinho mais alto que o ponto onde ele está, ele para (já está no mais alto);
- se houver um vizinho mais alto (cima, esquerda, direita e baixo), ele vai para o vizinho mais
  alto. Caso haja mais de um vizinho mais alto (mais de um ponto com a mesma altitude), ele vai
  para o último vizinho mais alto que encontrar (o Rei Gelado olha para os vizinhos na seguinte
  sequência: cima, esquerda, direita e baixo).

Sua tarefa na equipe de desenvolvimento do jogo é implementar uma função que recebe um terreno e
retorna uma string com o caminho que o Rei Gelado deve seguir para chegar ao ponto mais alto da sua
ilha. A string deve ter as direções que o Rei Gelado deve seguir, na ordem em que ele as segue,
separadas por "-" e finalizando com a string "FIM".

Por exemplo, se o terreno for:
<pre>
5 4 3
2 1 0
3 2 1
</pre>

...e o Rei Gelado começar na posição (1, 1) (que é o ponto no centro do terreno), a função deve
retornar a string "CIMA-ESQUERDA-FIM", pois o Rei Gelado vai primeiro para CIMA (0,1), depois
a ESQUERDA (0,0) e para por aí, terminando a string com FIM.

Inicialmente, defina o tipo Terreno como um mapa de altitudes (contendo as dimensões do terreno
e as altitudes de cada ponto) e o tipo Posicao, que representa uma posição no terreno e possui
dois atributos do tipo inteiro: linha e coluna.

Em seguida, implemente a função rumoAoTopo(), que recebe um terreno e a posição inicial do Rei
Gelado, e retorna uma string com o caminho que ele deve seguir para chegar ao ponto mais alto da
ilha.

OBS: Como o Rei Gelado se encontra em uma ilha, você pode assumir que a altitude de sua posição
inicial é sempre maior ou igual a 0. Além disso, o terreno sempre terá pelo menos uma linha e
uma coluna, ou seja, não há terrenos vazios.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

struct Posicao {
  int linha;
  int coluna;
};

struct Terreno {
  int profundidade;
  int largura;
  int altitudes[500][500];
};

// Dada uma posição, acha qual é o vizinho mais alto
Posicao vizinho_mais_alto(const Terreno &terreno, const Posicao &posicao) {
  // Vamos buscar os vizinhos nas quatro direções: CIMA, ESQUERDA, DIREITA e BAIXO
  Posicao deslocamentos[] = {
    { -1, 0 }, // CIMA
    { 0, -1 }, // ESQUERDA
    { 0, 1 },  // DIREITA
    { 1, 0 }   // BAIXO
  };
  // Inicializa a posição do vizinho mais alto como a posição atual porque se não houver vizinho mais alto,
  // então deve retornar a posição atual.
  Posicao pos = posicao;
  int alt_pos = terreno.altitudes[posicao.linha][posicao.coluna];

  // Percorre os deslocamentos, que vai gerar as posições dos vizinhos
  for(int i = 0; i < 4; ++i) {
    Posicao vizinho = {posicao.linha + deslocamentos[i].linha, posicao.coluna + deslocamentos[i].coluna};
    // Verifica se o vizinho está dentro dos limites do terreno
    if (vizinho.linha >= 0 && vizinho.linha < terreno.profundidade && vizinho.coluna >= 0 && vizinho.coluna < terreno.largura) {
      // Se estiver e for maior que a posição atual, atualiza a posição
      int alt_vizinho = terreno.altitudes[vizinho.linha][vizinho.coluna];
      if (alt_vizinho > alt_pos) {
        pos = vizinho;
        alt_pos = alt_vizinho;
      }
    }
  }
  return pos;
}

// Constrói um caminho rumo ao topo do terreno.
string rumoAoTopo(const Terreno &terreno, const Posicao &inicio) {
  string caminho = ""; // Inicializa a string do caminho inicialmente vazia
  Posicao atual = inicio;
  bool tem_vizinho_mais_alto = true; // variável de controle para o loop

  while (tem_vizinho_mais_alto) {
    // acha qual a posição do vizinho mais alto
    Posicao proximo = vizinho_mais_alto(terreno, atual);
    // se a posição retornada for igual à posição atual, significa que não há vizinho mais alto,
    // então o Rei Gelado para
    if (proximo.linha == atual.linha && proximo.coluna == atual.coluna) {
      tem_vizinho_mais_alto = false;
    }
    // senão, adiciona a direção do movimento ao caminho
    else if (proximo.linha < atual.linha) {
      caminho += "CIMA-";
    }
    else if (proximo.linha > atual.linha) {
      caminho += "BAIXO-";
    }
    else if (proximo.coluna < atual.coluna) {
      caminho += "ESQUERDA-";
    }
    else if (proximo.coluna > atual.coluna) {
      caminho += "DIREITA-";
    }
    // Agora, a posição atual deve ser a posição do vizinho mais alto
    atual = proximo;
  }
  caminho += "FIM"; // Finaliza o caminho com FIM
  return caminho;
}


// --- Testes ---
// Você pode definir novos testes para a sua função aqui

// Mas esta parte não pode ser alterada!
TEST_CASE("Testa o caminho do Rei Gelado em vários terrenos") {
  Terreno t1 = {3, 3, {
    {5, 4, 3},
    {2, 1, 0},
    {3, 2, 1}
  }};

  CHECK(rumoAoTopo(t1, Posicao{1, 1}) == "CIMA-ESQUERDA-FIM");
  CHECK(rumoAoTopo(t1, Posicao{0, 0}) == "FIM");
  CHECK(rumoAoTopo(t1, Posicao{2, 2}) == "ESQUERDA-ESQUERDA-FIM");
  CHECK(rumoAoTopo(t1, Posicao{2, 0}) == "FIM");
  CHECK(rumoAoTopo(t1, Posicao{1, 2}) == "CIMA-ESQUERDA-ESQUERDA-FIM");

  Terreno t2 = {2, 2, {
    {0, 2},
    {3, 1}
  }};
  CHECK(rumoAoTopo(t2, Posicao{0, 0}) == "BAIXO-FIM");
  CHECK(rumoAoTopo(t2, Posicao{0, 1}) == "FIM");
  CHECK(rumoAoTopo(t2, Posicao{1, 0}) == "FIM");
  CHECK(rumoAoTopo(t2, Posicao{1, 1}) == "ESQUERDA-FIM");
}