// #include <cmath>
#include <iostream>

// - Implementar uma função que calcula todos os primos dentro de um intervalo
// de inteiros. Ex: primos entre 2 e 10 são 2, 3, 5, 7.
int main() {
  int a, b;
  bool *is_deleted;

  std::cin >> a >> b;

  is_deleted = new bool[b];

  // debug
  int total_primers = 0;
  int total_steps = 0;

  for (int i = 1; i < b; i++) {
    is_deleted[i] = false;
  }

  // for (int k = 1; k < std::sqrt(b); k++) {
  for (int k = 1; k < b; k++) {
    total_steps++;

    if (is_deleted[k] == false) {
      bool stop = true;

      for (int j = k + (k + 1); j < b; j += (k + 1)) {
        is_deleted[j] = true;
        stop = false;
      }

      if (stop) {
        break;
      }
    }
  }

  for (int i = 1; i < b; i++) {
    if (is_deleted[i] == false and i >= a and i <= b) {
      // std::cout << i + 1 << std::endl;
      total_primers++;
    }
  }

  std::cout << "Total de primos " << total_primers << std::endl;
  std::cout << "Total de passos " << total_steps << std::endl;

  return 0;
}
