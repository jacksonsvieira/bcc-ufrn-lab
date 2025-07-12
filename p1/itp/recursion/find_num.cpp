#include <iostream>

bool find_num(int n, int tam, int sequence[]){
    if(tam == 1){
        return sequence[tam-1] == n;
    }

    return sequence[tam-1] == n or find_num(n, tam-1, sequence);
}

int main(){
    int sequence[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool has_num = find_num(0, 10, sequence);

    std::cout << (has_num ? "YES" : "NO") << "\n";
    return 0;
}