#include <iostream>

int sum(int tam, int sequence[]){
    if(tam == 1){
        return sequence[tam-1];
    }

    return sequence[tam-1] + sum(tam-1, sequence);
}

int main(){
    int sequence[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = sum(10, sequence);

    std::cout << result << "\n";
    return 0;
}