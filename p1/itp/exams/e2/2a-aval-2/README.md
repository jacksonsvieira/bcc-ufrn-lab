# Exam E2-2

## Cume

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

## Jornada

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