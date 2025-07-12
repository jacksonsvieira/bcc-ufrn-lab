#include <iostream>


int has_path(
    int maze[], 
    bool path[],
    bool path_solution[],
    int num_cols, 
    int player_pos_x, 
    int player_pos_y,
    int exit_pos_x,
    int exit_pos_y
){
    int player_index = player_pos_y*num_cols + player_pos_x;
    int exit_index = exit_pos_y*num_cols + exit_pos_x;

    if(player_pos_x < 0 or player_pos_x > num_cols-1 or player_pos_y < 0 or player_pos_y > num_cols-1){
        return false;
    }

    if(player_index == exit_index){
        return true;
    }

    if(path[player_index]){
        return false;
    }

    if(maze[player_index] == 1){
        return false;
    }

    path[player_index] = true;
    
    bool r1 = has_path(maze, path, path_solution, num_cols, player_pos_x+1, player_pos_y, exit_pos_x, exit_pos_y);
    bool r2 = has_path(maze, path, path_solution, num_cols, player_pos_x-1, player_pos_y, exit_pos_x, exit_pos_y);
    bool r3 = has_path(maze, path, path_solution, num_cols, player_pos_x, player_pos_y+1, exit_pos_x, exit_pos_y);
    bool r4 = has_path(maze, path, path_solution, num_cols, player_pos_x, player_pos_y-1, exit_pos_x, exit_pos_y);

    if(r1){
        int solution_player_index = player_pos_y*num_cols + player_pos_x+1;
        path_solution[solution_player_index] = true;
        return true;
    }

    if(r2){
        int solution_player_index = player_pos_y*num_cols + player_pos_x-1;
        path_solution[solution_player_index] = true;
        return true;
    }

    if(r3){
        int solution_player_index = (player_pos_y+1)*num_cols + player_pos_x;
        path_solution[solution_player_index] = true;
        return true;
    }

    if(r4){
        int solution_player_index = (player_pos_y-1)*num_cols + player_pos_x;
        path_solution[solution_player_index] = true;
        return true;
    }

    return false;
}

int main(){
    int n;
    int start_pos_x, start_pos_y, exit_pos_x, exit_pos_y;

    std::cin >> n; 

    int maze[n*n];
    bool path[n*n] = {false};


    for(int i = 0; i < (n*n); i++){
        std::cin >> maze[i];
    }

    std::cin >> start_pos_y >> start_pos_x >> exit_pos_y >> exit_pos_x;

    int num_cols = n;
    bool path_solution[n*n] = {false};

    int player_index = start_pos_y*num_cols + start_pos_x;
    path_solution[player_index] = true;

    bool has_solution = has_path(
        maze, 
        path,
        path_solution,
        n,
        start_pos_x, 
        start_pos_y,
        exit_pos_x,
        exit_pos_y
    );



    std::cout << (has_solution ? "YES" : "NO") << "\n";

    if(has_solution){
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                int index = i*n + k;
                std::cout << path_solution[index] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}

// TODO: Imprimir uma matriz apenas com o caminho feito por exemplo OK
// TODO: Criar testes automatizados
// TODO: Refatorar o codigo com principios de orientacao a objetos (& SOLID)
// TODO: Otimizar performance do codigo utilizando ponteiros e referencias para nao alocar mais memoria na stack