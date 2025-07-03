#include <iostream>

//a -> bq + r

int gdc(int a, int b, int step = 1) {
  std::cout << "Step " << step << ": gcd(" << a << ", " << b << ")" << std::endl;
  
  if (b == 0) {
    std::cout << "  -> Base case reached: b = 0, so gdc = " << a << std::endl;
    return a;
  }
  
  int remainder = a % b;
  std::cout << "  -> " << a << " = " << b << " * " << (a / b) << " + " << remainder << std::endl;
  std::cout << "  -> Next call: gdc(" << b << ", " << remainder << ")" << std::endl;
  std::cout << std::endl;

  return gdc(b, remainder, step + 1);
}

int main() {
  int a, b;
  char choice;

  std::cout << "=== GCD (Greatest Common Divisor) Calculator ===" << std::endl;
  std::cout << "Press CTRL-D at any time to exit the program." << std::endl;
  std::cout << std::endl;
  
  while (true) {
    std::cout << "Enter two integers to find their GCD:" << std::endl;
    
    std::cout << "Enter first number (a): ";
    if (!(std::cin >> a)) {
      break;
    }
    
    std::cout << "Enter second number (b): ";
    if (!(std::cin >> b)) {
      break;
    }
    
    std::cout << std::endl << "Calculating GCD of " << a << " and " << b << ":" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    int result = gdc(a, b);
    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Final result: GCD(" << a << ", " << b << ") = " << result << std::endl;
    std::cout << std::endl;
  }
  
  return 0;
}
