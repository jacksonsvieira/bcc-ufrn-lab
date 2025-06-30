#include <iostream>

struct Bezout {
  int gcd;
  int x;
  int y;
};

Bezout euclideanExtended(int a, int b, int step = 1) {
  std::cout << "Step " << step << ": gcd(" << a << ", " << b << ")" << std::endl;
  
  if (b == 0) {
    std::cout << "-> Base case reached: b = 0, so gcd = " << a << std::endl;
    std::cout << "-> Bezout coefficients: x = 1, y = 0" << std::endl;
    return {a, 1, 0};
  }

  int q = a / b;
  int r = a % b;
  
  std::cout << "-> " << a << " = " << b << " * " << q << " + " << r << std::endl;
  std::cout << "-> Next call: gcd(" << b << ", " << r << ")" << std::endl;

  Bezout res = euclideanExtended(b, r, step + 1);
  
  int newX = res.y;
  int newY = res.x - q * res.y;
  
  std::cout << "-> Back to Step " << step << ": x = " << newX << ", y = " << newY << std::endl;
  std::cout << "-> Verification: " << a << " * " << newX << " + " << b << " * " << newY << " = " << (a * newX + b * newY) << std::endl;
  
  return {res.gcd, newX, newY};
}

int main() {
  std::cout << "=== Extended Euclidean Algorithm (Bezout Coefficients) Calculator ===" << std::endl;
  std::cout << "Calculates the GCD and Bezout coefficients (x, y) such that ax + by = gcd(a, b)" << std::endl;
  std::cout << "Press CTRL-D at any time to exit the program" << std::endl;
  std::cout << std::endl;

  int a, b;
  
  while (true) {
    std::cout << "Enter two integers (a b): ";
    
    if (!(std::cin >> a >> b)) {
      break;
    }
    
    std::cout << std::endl;
    std::cout << "Processing Extended Euclidean Algorithm with a = " << a << ", b = " << b << ":" << std::endl;
    std::cout << "----" << std::endl;
    
    Bezout result = euclideanExtended(a, b);
    
    std::cout << "----" << std::endl;
    std::cout << "Final result:" << std::endl;
    std::cout << "GCD(" << a << ", " << b << ") = " << result.gcd << std::endl;
    std::cout << "Bezout coefficients: x = " << result.x << ", y = " << result.y << std::endl;
    std::cout << "Proof: " << a << " * " << result.x << " + " << b << " * " << result.y << " = " << result.gcd << std::endl;
    std::cout << std::endl;
  }
  
  return 0;
}
