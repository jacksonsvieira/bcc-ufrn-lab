#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

const std::string LETTERS {
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

const std::unordered_map<char, int> create_letter_to_index_mapping() {
  std::unordered_map<char, int> letter_to_index_map;

  for (int i = 0; i < LETTERS.length(); i++) {
    letter_to_index_map[LETTERS[i]] = i;
  }

  return letter_to_index_map;
}

const std::unordered_map<char, int> LETTER_INDEX = create_letter_to_index_mapping();

std::string encrypt(std::string word, int k) {
  std::string encrypted_word = "";

  for (int i = 0; i < word.length(); i++) {
    char current_char = word[i];

    if (current_char == 32) {
      encrypted_word += current_char;
      continue;
    }

    int index_letter = LETTER_INDEX.at(current_char);
    int new_letter_index = (index_letter + k) % 52;
    encrypted_word += LETTERS[new_letter_index];
  }

  return encrypted_word;
}

std::string decrypt(std::string word, int k) {
  std::string decrypted_word = "";

  for (int i = 0; i < word.length(); i++) {
    char current_char = word[i];

    if (current_char == 32) {
      decrypted_word += current_char;
      continue;
    }

    int index_letter = LETTER_INDEX.at(current_char);
    int new_letter_index = (index_letter - k + 52) % 52;
    decrypted_word += LETTERS[new_letter_index];
  }

  return decrypted_word;
}

int main() {
  std::cout << "=== Caesar Cipher Encoder/Decoder ===" << std::endl;
  std::cout << "Encrypts and decrypts text using the Caesar cipher with customizable shift" << std::endl;
  std::cout << "Press CTRL-D at any time to exit the program" << std::endl;
  std::cout << std::endl;

  while (true) {
    int k;
    std::string word;
    
    std::cout << "Enter the shift value (k): ";
    if (!(std::cin >> k)) {
      break;
    }
    
    std::cin.ignore();
    
    std::cout << "Enter text to encrypt: (a-z) (A-Z) (space) ";
    if (!std::getline(std::cin, word)) {
      break;
    }

    std::cout << std::endl;

    std::string encrypted_word = encrypt(word, k);
    std::string decrypted_word = decrypt(encrypted_word, k);

    std::cout << "Step 1: Encryption" << std::endl;
    std::cout << "-> Original text: \"" << word << "\"" << std::endl;
    std::cout << "-> Encrypted text: \"" << encrypted_word << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "Step 2: Decryption (verification)" << std::endl;
    std::cout << "-> Decrypted text: \"" << decrypted_word << "\"" << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
