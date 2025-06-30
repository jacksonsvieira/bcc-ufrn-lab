#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

struct Bezout {
  int gcd;
  int x;
  int y;
};

const std::string LETTERS{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
const int LETTERS_LENGHT = 52;

const std::unordered_map<char, int> create_letter_to_index_mapping() {
  std::unordered_map<char, int> letter_to_index_map;

  for (int i = 0; i < LETTERS.length(); i++) {
    letter_to_index_map[LETTERS[i]] = i;
  }

  return letter_to_index_map;
}

const std::unordered_map<char, int> LETTER_INDEX = create_letter_to_index_mapping();

Bezout euclideanExtend(int a, int b) {
  if (b == 0)
    return {a, 1, 0};
  int q = a / b;
  int r = a % b;
  Bezout res = euclideanExtend(b, r);
  return {res.gcd, res.y, res.x - q * res.y};
}

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int choose_e(int phi_n) {
  std::vector<int> common_e = {3, 5, 17, 257, 65537};

  for (int e : common_e) {
    if (e < phi_n && gcd(e, phi_n) == 1) {
      return e;
    }
  }

  int e = 3;
  while (e < phi_n) {
    if (gcd(e, phi_n) == 1) {
      return e;
    }
    e += 2;
  }

  return 3;
}

int calculate_d(int e, int phi_n) {
    Bezout bez = euclideanExtend(e, phi_n);
    return (bez.x % phi_n + phi_n) % phi_n;
}

int mod_exp(int base, int exp, int mod) {
  int result = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  };

  return result;
}


// c = m^e mod n
int encrypt_char(char c, int e, int n) {
  return mod_exp(LETTER_INDEX.at(c), e, n);
}

// inverse function in form of c^d mod n
char decrypt_char(int c, int d, int n) {
  int index = mod_exp(c, d, n);
  return LETTERS[index];
}

int main() {
  std::cout << "=== RSA ALGORITHM ===" << std::endl;
  std::cout << "Press CTRL-D to quit" << std::endl;
  std::cout << std::endl;
  
  while (true) {
    int p, q;
    std::cout << "Enter prime p: ";
    if (!(std::cin >> p)) {
      break;
    }
    
    std::cout << "Enter prime q: ";
    if (!(std::cin >> q)) {
      break;
    }

    std::cout << std::endl;
    std::string message = "pleasework";

    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = choose_e(phi_n);
    int d = calculate_d(e, phi_n);

    std::cout << "=== ALGORITHM PARAMETERS ===" << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "p * q (n) = " << n << std::endl;
    std::cout << "Euler's totient function (phi_n) = " << phi_n << std::endl;
    std::cout << "Public exponent (e) = " << e << std::endl;
    std::cout << "Private exponent (d) = " << d << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << std::endl;

    std::vector<int> cypher;
    for (char ch : message) {
      cypher.push_back(encrypt_char(ch, e, n));
    }

    std::cout << "=== ENCRYPTED TEXT ===" << std::endl;
    std::cout << "Encrypted:" << "\n";
    for (int c : cypher) {
      std::cout << c;
    }
    std::cout << std::endl;

    std::string decrypted = "";
    for (int c : cypher) {
      decrypted += decrypt_char(c, d, n);
    }

    std::cout << "=== DECRYPTED TEXT ===" << std::endl;
    std::cout << "Decrypted:" << "\n";
    std::cout << decrypted << "\n";
    std::cout << "Success: " << (message == decrypted ? "YES" : "NO") << "\n";
    std::cout << std::endl;
  }
  
  return 0;
}
