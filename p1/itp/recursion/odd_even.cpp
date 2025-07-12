#include <iostream>

bool even(int n){
    return (n == 0 or odd(n-1));
}

bool odd(int n){
    return (n != 0 and even(n-1));
}


int main(){
    int is_even = even(10);
    std::cout << (is_even ? "YES" : "NO") << "\n";
    return 0;
}