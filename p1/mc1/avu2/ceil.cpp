#include <iostream>

// n = x + f
// x >= 0 (dado 0 < f < 1 logo n < x < n+1)
// ceil -> n < x < n+1
int ceil(float x){
  int n = 0;
  while(true){
    if(x < 0){
      if(n-1 < x){
        return n;
      }
      n--;
    } else {
      if(n+1 > x){
        return n;
      }
      n++;
    }
  }
}

int main(){
  std::cout << ceil(2.5) << std::endl;
  std::cout << ceil(2.0) << std::endl;
  std::cout << ceil(0.5) << std::endl;
  std::cout << ceil(0.0) << std::endl;
  std::cout << ceil(-1.5) << std::endl;
  std::cout << ceil(-1.0) << std::endl;
  return 0;
}
