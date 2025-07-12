/*
No jogo "Gelado", que você começou a desenvolver anteriormente, uma nova tarefa lhe foi passada.
No jogo, um dos personagens deve realizar uma jornada épica, desbravando pêntanos, desertos e geleiras,
ao cruzar todo o terreno do jogo. Só que o personagem é corajoso, mas não é bobo! Se ele precisa cruzar
todo o terreno, ele vai escolher o trajeto de menor esforço possível.

Nessa jornada, o personagem terá algumas restrições. Ele só pode cruzar o terreno em linha reta, seja
na horizontal ou na vertical. Ou seja, se ele começar a jornada na linha de índice 2, ele deve
atravesar todas as colunas da linha 2, da primeira (de índice 0) até a última. O mesmo serve para o
caso dele começar a jornada em uma coluna. Se ele começar na coluna de índice 3, ele deve atravessar
todas as linhas da coluna 3, da primeira (de índice 0) até a última.

Além disso, para escolher qual o trajeto de menor esforço, ele precisa conhecer o tipo de terreno
que está atravessando. Ele pode atravessar 4 tipos de terrenos: pântano, planície, deserto e geleira.
Cada um desses tipos vai ter um custo associado ao esforço de atravessá-lo. Atravessar um pântano
tem custo 2, uma planície tem custo 1, um deserto tem 3 e uma geleira 4.

O esforço de um trajeto é definido como a soma dos custos de atravessar cada ponto do terreno (considerando
o tipo de terreno) mais o custo associado às diferenças de altitude entre dois pontos consecutivos
(afinal, subir e descer montanhas cansa).

Por exemplo, digamos que o terreno seja definido por um mapa 4x5 com as seguintes altitudes e tipos
de terreno (onde P representa pântano, L planície, D deserto e G geleira):
<pre>
2 0 1 2 3      P P L L G
2 1 0 2 5      P L P L G
0 1 2 3 4      P D D G G
1 2 0 1 2      P D L L D
</pre>

Se a jornada for realizada na linha 0, o esforço de cada trajeto será calculado pelo custo das subidas
e descidas:
<pre>
|2 - 0| = 2
|0 - 1| = 1
|1 - 2| = 1
|2 - 3| = 1
total = 5
</pre>
... mais o custo de atravessar os tipos de terreno:
<pre>
2 (pântano) + 2 (pântano) + 1 (planície) + 1 (planície) + 4 (geleira) = 10
</pre>
Assim, o esforço total da jornada na linha 0 será 5 (custo das altitudes) + 10 (custo dos tipos de
terreno) = 15.

Na sua tarefa, você deve definir um tipo chamado TipoTerreno, capaz de representar os quatro tipos
de terreno (pântano, planície, deserto e geleira) e um tipo chamado Terreno, que contém as
dimensões do terreno (profundidade e largura), bem como as altitudes e os tipos de terreno de cada
ponto (usando TipoTerreno). Esse tipo deve ter a capacidade de representar terrenos com até 500x500
pontos.

Em seguida, você deve implementar uma função chamada menor_jornada(), que recebe um terreno e
retorna o menor esforço que o personagem pode fazer para realizar a jornada, seja na horizontal
ou na vertical.

OBS: O terreno sempre terá pelo menos uma linha e uma coluna, ou seja, não há terrenos vazios. Além
disso, sabe-se que uma jornada nunca terá esforço maior que 1000000.

DICA: Quebre o problema em problemas menores! Por exemplo, você pode quebrar no subproblema de
calcular o esforço de uma linha ou de uma coluna. Crie funções para isso, teste se elas funcionam
e depois use essas funções no problema principal.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

enum TipoTerreno {
  PLANICIE,
  PANTANO,
  DESERTO,
  GELEIRA
};

struct Terreno {
  int profundidade; // número de linhas da matriz
  int largura;      // ... e o número de colunas
  int altitudes[500][500]; // matriz com as altitudes do terreno
  TipoTerreno tipos[500][500]; // matriz com os tipos de terreno
};

int esforco_terreno(TipoTerreno tipo) {
  switch (tipo) {
    case PANTANO: return 2;
    case PLANICIE: return 1;
    case DESERTO: return 3;
    case GELEIRA: return 4;
    default: return 0; // caso não esperado
  }
}

// Calcula o esforço para percorrer uma linha do terreno
int esforco_linha(const Terreno &terreno, int linha) {
  int esforco = 0;
  // percorre até o penúltimo ponto porque a gente está sempre comparando com o próximo
  for (int j = 0; j < terreno.largura - 1; ++j) {
    // o esforço é a soma das diferenças de altitude entre pontos consecutivos ...
    esforco += abs(terreno.altitudes[linha][j] - terreno.altitudes[linha][j + 1]);
    // ... mais o esforço do tipo de terreno do ponto atual
    esforco += esforco_terreno(terreno.tipos[linha][j]);
  }
  // como fomos até o penúltimo, precisamos adicionar o esforço do último ponto
  esforco += esforco_terreno(terreno.tipos[linha][terreno.largura - 1]); // último ponto da linha
  return esforco;
}

// Calcula o esforço para percorrer uma coluna do terreno.
// É similar ao cálculo do esforço de uma linha (função anterior), só que agora é da coluna.
int esforco_coluna(const Terreno &terreno, int coluna) {
  int esforco = 0;
  for (int i = 0; i < terreno.profundidade - 1; ++i) {
    esforco += abs(terreno.altitudes[i][coluna] - terreno.altitudes[i + 1][coluna]);
    esforco += esforco_terreno(terreno.tipos[i][coluna]);
  }
  esforco += esforco_terreno(terreno.tipos[terreno.profundidade - 1][coluna]); // último ponto da coluna
  return esforco;
}


// A função menor_jornada recebe um terreno e retorna o menor esforço
int menor_jornada(const Terreno &terreno) {
  int menor_esforco = 1000000;

  // Calcula o esforço para cada linha e atualiza o menor esforço, se necessário
  for (int i = 0; i < terreno.profundidade; ++i) {
    int esforco = esforco_linha(terreno, i);
    if (esforco < menor_esforco) {
      menor_esforco = esforco;
    }
  }

  // Calcula o esforço para cada coluna e atualiza o menor esforço, se necessário
  for (int j = 0; j < terreno.largura; ++j) {
    int esforco = esforco_coluna(terreno, j);
    if (esforco < menor_esforco) {
      menor_esforco = esforco;
    }
  }
  return menor_esforco;
}

// --- Testes ---
// Você pode definir novos testes para a sua função aqui

// Mas esta parte não pode ser alterada!
TEST_CASE("Testa o menor esforço da jornada em vários terrenos") {
  Terreno t1 = {3, 3,
    { // altitudes
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    },
    { // tipos de terreno
      {PANTANO, PANTANO,  PLANICIE},
      {PANTANO, PLANICIE, GELEIRA},
      {PANTANO, DESERTO,  GELEIRA}
    }
  };

  Terreno t2 = {2, 2,
    { // altitudes
      {0, 2},
      {3, 1}
    },
    { // tipos de terreno
      {PANTANO, PLANICIE},
      {DESERTO, PANTANO}
    }
  };

  Terreno t3 = {1, 1,
    { // altitudes
      {5}
    },
    { // tipos de terreno
      {GELEIRA}
    }
  };

  Terreno t4 = {4, 5,
    { // altitudes
      {2, 0, 1, 2, 3},
      {2, 1, 0, 2, 5},
      {0, 1, 2, 3, 4},
      {1, 2, 0, 1, 2}
    },
    { // tipos de terreno
      {PANTANO, PANTANO,  PLANICIE, PLANICIE, GELEIRA},
      {PANTANO, PLANICIE, PANTANO,  PLANICIE, GELEIRA},
      {PANTANO, DESERTO,  DESERTO,  GELEIRA,  GELEIRA},
      {PANTANO, DESERTO,  PLANICIE, PLANICIE, DESERTO}
    }
  };

  CHECK(menor_jornada(t1) == 7);  // Jornada na linha 0
  CHECK(menor_jornada(t2) == 4);  // Jornada na coluna 1
  CHECK(menor_jornada(t3) == 4);  // Só conta o tipo de terreno (geleira)
  CHECK(menor_jornada(t4) == 10); // Jornada na coluna 3
}