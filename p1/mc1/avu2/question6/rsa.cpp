#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct Bezout {
  int64_t gcd;
  int64_t x;
  int64_t y;
};

Bezout euclideanExtend(int64_t a, int64_t b) {
  if (b == 0)
    return {a, 1, 0};
  int64_t q = a / b;
  int64_t r = a % b;
  Bezout res = euclideanExtend(b, r);
  return {res.gcd, res.y, res.x - q * res.y};
}


int64_t gcd(int64_t a, int64_t b) {
  while (b != 0) {
    int64_t r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int64_t choose_e(int64_t phi_n) {
  std::vector<int64_t> common_e = {3, 5, 17, 257, 65537};

  for (int64_t e : common_e) {
    if (e < phi_n && gcd(e, phi_n) == 1) {
      return e;
    }
  }

  int64_t e = 3;
  while (e < phi_n) {
    if (gcd(e, phi_n) == 1) {
      return e;
    }
    e += 2;
  }

  return 3;
}

uint64_t mod_exp(uint64_t base, uint64_t exp, uint64_t mod) {
  uint64_t result = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

int calculate_d(int e, int phi_n) {
    Bezout bez = euclideanExtend(e, phi_n);
    return (bez.x % phi_n + phi_n) % phi_n;
}

uint64_t encrypt_char(uint8_t ch, uint64_t e, uint64_t n) {
  return mod_exp(ch, e, n);
}

uint8_t decrypt_char(uint64_t c, uint64_t d, uint64_t n) {
  uint64_t m = mod_exp(c, d, n);
  if (m > 255) {
    std::cerr << "Warning: decrypted value greater than 255: " << m << "\n";
    return 0;
  }
  return static_cast<uint8_t>(m);
}

bool is_prime(uint64_t n) {
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  for (uint64_t i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  std::string message = "jackson.serafim@vgmailcom 1234567890 cplusplus";

  uint64_t p, q;
  p = 9791;
  q = 7529;

  uint64_t n = p * q;
  uint64_t phi_n = (p - 1) * (q - 1);

  uint64_t e = choose_e(phi_n);
  int64_t d = calculate_d(e, phi_n);

  if (d == -1) {
    std::cout << "Error: could not calculate d!\n";
    return 1;
  }

  std::cout << "\n=== RSA PARAMETERS ===\n";
  std::cout << "p = " << p << "\n";
  std::cout << "q = " << q << "\n";
  std::cout << "n = " << n << "\n";
  std::cout << "φ(n) = " << phi_n << "\n";
  std::cout << "e = " << e << "\n";
  std::cout << "d = " << d << "\n";

  if ((e * d) % phi_n != 1) {
    std::cout << "Error: e * d is not congruent to 1 mod φ(n)!\n";
    std::cout << "e * d mod φ(n) = " << (e * d) % phi_n << "\n";
    return 1;
  }

  std::cout << "\n=== ENCRYPTION PROCESS ===\n";
  std::cout << "Original:" << "\n";
  std::cout << message << "\n";

  std::vector<uint64_t> cypher;
  for (unsigned char ch : message) {
    uint64_t encrypted = encrypt_char(ch, e, n);
    cypher.push_back(encrypted);
  }

  std::cout << "\nEncrypted:" << "\n";
  for (size_t i = 0; i < cypher.size(); i++) {
    std::cout << cypher[i];
  }
  std::cout << "\n";

  std::cout << "\n=== DECRYPTION PROCESS ===\n";
  std::string decrypted = "";
  bool success = true;

  for (size_t i = 0; i < cypher.size(); i++) {
    uint8_t decrypted_char = decrypt_char(cypher[i], d, n);
    if (decrypted_char == 0 && cypher[i] != encrypt_char(0, e, n)) {
      success = false;
      std::cout << cypher[i] << " -> ERROR in decryption\n";
    } else {
      decrypted += decrypted_char;
    }
  }

  std::cout << "\nDecrypted:" << "\n";
  std::cout << decrypted << "\n";
  std::cout << "Success: " << (decrypted == message ? "YES" : "NO") << "\n";
  std::cout << std::endl;

  return 0;
}
