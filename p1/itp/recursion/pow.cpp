#include <iostream>


// b^n = b*(b^n-1)
int pow(int b, int e){
    if(e == 0){
        return 1;
    }

    return b*pow(b, e-1);
}

int main(){
    int result = pow(2, 5);
    std::cout << "2^5=" << result << "\n";
    return 0;
}