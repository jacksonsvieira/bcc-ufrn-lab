#include <iostream>
#include <vector>

// int is_prime(int n) {
//     if (n <= 1) {
//         return false;
//     }

//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
    
//     return true;
// }

std::vector<int> findPrimesInRange(int a, int b) {
    std::vector<int> primes;
    
    if (b < 2) {
        return primes;
    }
    
    std::vector<bool> is_prime(b + 1, true);
    is_prime[0] = is_prime[1] = false; 

    // Sieve
    for (int i = 2; i * i <= b; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = std::max(2, a); i <= b; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

void displayResults(const std::vector<int>& primes, int a, int b) {
    std::cout << "\n=== PRIME NUMBERS FINDER ===" << std::endl;
    std::cout << "Range: [" << a << ", " << b << "]" << std::endl;
    std::cout << "=============================" << std::endl;
    
    if (primes.empty()) {
        std::cout << "No prime numbers found in the given range." << std::endl;
    } else {
        std::cout << "Prime numbers found:" << std::endl;
        for (size_t i = 0; i < primes.size(); i++) {
            std::cout << primes[i];
            if (i < primes.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nTotal primes found: " << primes.size() << std::endl;
    std::cout << "=============================" << std::endl;
}


int main() {
    int a, b;
    
    std::cout << "=== PRIME NUMBERS FINDER ===" << std::endl;
    std::cout << "Enter the range to search for prime numbers:" << std::endl;
    
    std::cout << "Starting number (a): ";
    std::cin >> a;
    
    std::cout << "Ending number (b): ";
    std::cin >> b;
    
    if (a > b) {
        std::swap(a, b);
        std::cout << "Note: Swapped values to ensure a <= b" << std::endl;
    }
    
    std::vector<int> primes = findPrimesInRange(a, b);
    
    displayResults(primes, a, b);
    
    return 0;
}
