#include <iostream>

struct Position {
    int x;
    int y;
};

int has_path(
    int maze[], 
    bool seen[],
    bool path_solution[],
    int num_cols, 
    Position playerPos,
    Position exitPos
){
    int player_index = playerPos.y*num_cols + playerPos.x;
    int exit_index = exitPos.y*num_cols + exitPos.x;

    if(playerPos.x < 0 or playerPos.x > num_cols-1 or playerPos.y < 0 or playerPos.y > num_cols-1){
        return false;
    }

    if(player_index == exit_index){
        return true;
    }

    if(seen[player_index]){
        return false;
    }

    if(maze[player_index] == 1){
        return false;
    }

    seen[player_index] = true;

    const Position neighbours[4] = {
        {playerPos.x + 1, playerPos.y},
        {playerPos.x - 1, playerPos.y},
        {playerPos.x,     playerPos.y + 1},
        {playerPos.x,     playerPos.y - 1},
    };

    for(const Position& next : neighbours){
        if(has_path(maze, seen, path_solution, num_cols, next, exitPos)){
            int solution_player_index = next.y*num_cols + playerPos.x;
            path_solution[solution_player_index] = true;
            return true;
        }
    }


    return false;
}

int main(){
    int num_cols;
    Position playerPos;
    Position exitPos;

    std::cin >> num_cols; 

    int maze[num_cols*num_cols];
    bool path[num_cols*num_cols] = {false};


    for(int i = 0; i < (num_cols*num_cols); i++){
        std::cin >> maze[i];
    }

    std::cin >> playerPos.y >> playerPos.x >> exitPos.y >> exitPos.x;

    bool path_solution[num_cols*num_cols] = {false};
    int player_index = playerPos.y*num_cols + playerPos.x;
    path_solution[player_index] = true;

    bool has_solution = has_path(
        maze, 
        path,
        path_solution,
        num_cols,
        playerPos,
        exitPos
    );

    std::cout << (has_solution ? "YES" : "NO") << "\n";

    if(has_solution){
        for(int i = 0; i < num_cols; i++){
            for(int k = 0; k < num_cols; k++){
                int index = i*num_cols + k;
                std::cout << path_solution[index] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}

// TODO: Imprimir uma matriz apenas com o caminho feito por exemplo OK
// TODO: Refatorar o codigo com principios de orientacao a objetos (& SOLID)
// TODO: Otimizar performance do codigo utilizando ponteiros e referencias para nao alocar mais memoria na stack
// TODO: Criar testes automatizados