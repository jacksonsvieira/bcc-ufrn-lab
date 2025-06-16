#include <iostream>

// n = x + f
// x >= 0 (dado 0 < f < 1 logo n < x < n+1)
// ceil -> n < x < n+1
int floor(float x) {
  int n = 0;
  while (true) {
    if (n == x)
      return n;

    if (x < 0) {
      if (n < x) {
        return n;
      }
      n--;
    } else if (x > 0) {
      if (n > x) {
        return n;
      }
      n++;
    }
  }
}

int main() {
  std::cout << floor(2.5) << std::endl;
  std::cout << floor(2.0) << std::endl;
  std::cout << floor(0.5) << std::endl;
  std::cout << floor(0.0) << std::endl;
  std::cout << floor(-1.5) << std::endl;
  std::cout << floor(-1.0) << std::endl;
  return 0;
}
