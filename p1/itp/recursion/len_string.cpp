#include <iostream>

int len_string(char s[]){
    if(*s == '\0') return 0;
    return 1 + len_string(s+1);
}

int main(){
    char s[16] = "hello";

    int lenght = len_string(s);
    std::cout << (lenght == 5 ? "YES" : "NO") << "\n";
    return 0;
}