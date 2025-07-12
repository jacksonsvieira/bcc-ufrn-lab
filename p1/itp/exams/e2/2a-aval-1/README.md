# Exam E2-1

## Terreno

Mapa de altitudes (ou de alturas) é uma forma de representar um terreno, onde cada ponto do mapa
possui uma altitude associada. Ele pode ser representado por uma matriz de inteiros, onde cada
elemento da matriz representa a altitude de um ponto específico do terreno. Por exemplo, na matriz
3x3 abaixo, cada número representa a altitude de um ponto do terreno:

<pre>
1 2 3
4 5 6
7 8 9
</pre>

Neste exemplo, o ponto (0, 0) tem altitude 1, o ponto (1, 1) tem altitude 5 e assim por diante.

Defina um novo tipo de dado, chamado Terreno, para representar um mapa de altitudes. O mapa deve
ter, além de suas altitudes, suas dimensões (profundidade e largura), e deve ter a capacidade de
representar terrenos com até 500x500 pontos.

Em seguida, escreva uma função que recebe um terreno e retorna a maior altitude presente nesse
terreno. Terrenos vazios devem retornar 0.


## Segredo

Os mapas de altitudes são usados em diversas áreas da computação, como em simulações, sistemas
de informação geográfica (SIG) e jogos.

Você foi chamado para implementar um novo jogo, no qual o jogador precisa encontrar um segredo
escondido no ambiente. O segredo é uma senha formada por letras escondidas nos vales do terreno.

Nesse jogo, um vale é definido como um ponto do terreno que é menor que todos os seus
vizinhos imediatos (cima, baixo, esquerda, direita e nas diagonais). A partir da posição (linha
e coluna) de cada vale, é possível saber o índice (através da fórmula largura * linha + coluna)
da letra a ser usada em uma "chave de decodificação". A junção de todas as letras correspondentes
aos vales do terreno forma a senha do segredo. A sequência das letras segue a ordem de leitura
do terreno, de cima para baixo e da esquerda para a direita.

Por exemplo, considere o seguinte terreno:

<pre>
1 0 3
4 5 6
7 8 4
</pre>

Apenas os pontos das posições (0, 1) e (2, 2) são vales, pois:
- O ponto (0, 1) com valor 0 é menor que seus vizinhos: 1, 3, 4, 5, 6.
- O ponto (2, 2) com valor 4 é menor que seus vizinhos: 5, 6, 8.

Assim, como o terreno tem largura de 3, teremos os seguintes índices correspondentes aos vales:
- Para o ponto (0, 1): 3 * 0 + 1 = 1
- Para o ponto (2, 2): 3 * 2 + 2 = 8

Digamos que a chave de decodificação seja "eosqtaupiw", então a senha do segredo será formada
pelas letras nos índices 1, que é 'o', e 8, que é 'i'. Logo, o resultado é a senha "oi".

Escreva uma função que recebe um terreno (mesmo tipo definido na atividade "Terreno") e uma chave
de decodificação, e retorna a senha procurada pelo jogador. Se não houver vales, a função deve
retornar uma string vazia.

OBS: Se o índice correspondente a um vale for maior que o tamanho da chave de decodificação, esse
índice deve ser desconsiderado.

DICA: Quebre o problema em problemas menores! Por exemplo, você pode quebrar no subproblema de
verificar se um ponto do terreno é um vale. Crie uma função para isso, teste se ela funciona e
depois use essa função no problema principal.


## Gelado

No reino tão-tão distante, havia um rei tão frio, mas tão frio, que tudo que tocava congelava...
e tudo que tocava o que tocava também congelava. Assim, o mundo só não vivia uma era glacial, onde
tudo estaria congelado, porque o reino ficava numa ilha" (bem... e o mar salgado não congelava).

Assim começa o enredo do jogo "Gelado", que você foi convidado a fazer parte da equipe de
desenvolvimento. Sua primeira tarefa é implementar uma função para verificar se o jogador
se encontra na fatídica ilha do "Rei Gelado" (Não! Não é o mesmo da Hora de Aventura! Outro cara
pegou a coroa de Evergreen).

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

<pre>
-1  0  1  2  3
-3 -1  0  2  5
 0  1  2  3  4
 1 -1  0  1  2
</pre>

Nesse terreno, há apenas uma ilha, pois todos os pontos com altitude maior ou igual a 0 estão
conectados. Como há apenas uma ilha e o rei se encontra na ilha, então todos os pontos da ilha vão
estar congelados. Assim, se o jogador estiver na posição (3, 0), a função deve retornar true,
pois o jogador está na ilha do Rei Gelado. Porém, se o jogador estiver na posição (0, 0), a função
deve retornar false, pois o jogador está no mar.

Outro exemplo. Considere o seguinte terreno e o rei ainda na posição (1, 3).

<pre>
-1  0  1  2  3
-3 -1  0  2  0
-2 -1 -1 -1 -1
-2 -1 -2  1  2
</pre>

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