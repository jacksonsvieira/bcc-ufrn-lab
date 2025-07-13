#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

// --- Testes ---
// Você pode definir novos testes para a sua função aqui

struct Terreno {
    int largura;
    int profundidade;
    int alturas[500][500];
};

bool verificar_se_eh_vale(Terreno mapa, int pos_x, int pos_y){
    if(mapa.profundidade == 1 && mapa.largura == 1)
        return false;

    int vizinhos_adjacentes[8][2] = {
        {pos_x-1, pos_y}, // -1 1 // FORA
        {pos_x+1, pos_y}, // 1 1
        {pos_x, pos_y-1}, // 0 0
        {pos_x, pos_y+1}, // 0 2
        {pos_x+1, pos_y+1}, // 1 2
        {pos_x-1, pos_y-1}, // -1 0 // FORA
        {pos_x-1, pos_y+1}, // -1 1 // FORA
        {pos_x+1, pos_y-1}, // 1 0
    };

    int ponto = mapa.alturas[pos_y][pos_x];

    for(auto& vizinho : vizinhos_adjacentes){
        int x = vizinho[0];
        int y = vizinho[1];

        if(x < 0 || x > mapa.largura - 1 || y < 0 || y > mapa.profundidade - 1){
            continue;
        }

        if(ponto >= mapa.alturas[y][x]){
            return false;
        }
    }
    
    return true;
}

std::string senha(Terreno mapa, std::string senha_criptografada){
    std::string segredo = "";

    if(senha_criptografada == ""){
        return "";
    }

    for (int i = 0; i < mapa.profundidade; i++)
    {
        for (int k = 0; k < mapa.largura; k++)
        {
            bool eh_vale = verificar_se_eh_vale(mapa, k, i);

            if(eh_vale){
                int index = mapa.largura * i + k;
                if(index > senha_criptografada.length()){
                    continue;
                }
                segredo += senha_criptografada[index];
            }
        }
        
    }
    


    return segredo;
}


// int main(){
//     Terreno t1 = {3, 3, {{1, 0, 3}, {4, 5, 6}, {7, 8, 4}}}; // Terreno 3x3
//     senha(t1, "eosqtaupiw");
//     return 0;
// }

TEST_CASE("Testa a senha formada por um terreno e uma chave de decodificação") {
  Terreno t1 = {3, 3, {{1, 0, 3}, {4, 5, 6}, {7, 8, 4}}}; // Terreno 3x3
  Terreno t2 = {2, 2, {{1, 2}, {3, 1}}};       // Terreno 2x2 sem vales (vizinhos nas diagonais são iguais)
  Terreno t3 = {1, 1, {{5}}};                  // Terreno 1x1 não tem vale
  Terreno t4 = {2, 3, {{1, 0, 3}, {4, 5, 6}}}; // Terreno 2x3 com um vale 

  CHECK(senha(t1, "eosqtaupiw") == "oi");
  CHECK(senha(t1, "abcde") == "b");      // Testa com chave menor que número de vales
  CHECK(senha(t1, "") == "");            // Testa com chave vazia
  CHECK(senha(t2, "dshf") == "");        // Terreno 2x2 sem vales
  CHECK(senha(t3, "cjksfdj") == "");     // Terreno 1x1 não tem vale
  CHECK(senha(t4, "eosqtaupiw") == "o"); // Terreno 2x3 com um vale
}