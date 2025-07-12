#include <iostream>

int largest_num(int tam, int sequence[]){
    if(tam == 1){
        return sequence[tam-1];
    }

    int largest = largest_num(tam-1, sequence);
    return largest > sequence[tam-1] ? largest : sequence[tam-1];
}

int main(){
    int sequence[10] = {1, 2, 3, 4, 5, 18, 7, 8, 9, 10};
    int largest_n = largest_num(10, sequence);

    std::cout << largest_n << "\n";
    return 0;
}