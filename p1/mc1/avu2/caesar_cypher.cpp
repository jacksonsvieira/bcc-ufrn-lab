#include "unordered_map"
#include <iostream>

// TODO: Improvements use pointers to otimize performance and memory, this is
// simple i think i should use ASCII table for example encrypt full texts not
// only simple texts with abcdefghijklmnopqrstuvwxyz and should handle maybe
// accents receive a file text as a input and return a string in terminal ou
// generate a file output. handle too upercases letters.

const std::string letters{"abcdefghijklmnopqrstuvwxyz"};

std::unordered_map<char, int> create_hash() {
  std::unordered_map<char, int> alfabet;

  for (int i = 0; i < letters.length(); i++) {
    alfabet[letters[i]] = i;
  }

  return alfabet;
}

std::string encrypt(std::string word, int k) {
  std::unordered_map<char, int> hash = create_hash();
  std::string encrypeted_word = "";

  for (int i = 0; i < word.length(); i++) {
    char lowercased_letter = tolower(word[i]);
    if (lowercased_letter == 32) {
      encrypeted_word += lowercased_letter;
      continue;
    }

    int index_letter = hash[lowercased_letter];
    int new_letter_index = (index_letter + k) % 26;
    encrypeted_word += letters[new_letter_index];
  }

  return encrypeted_word;
}

std::string decrypt(std::string word, int k) {
  std::unordered_map<char, int> hash = create_hash();
  std::string decryped_word = "";

  for (int i = 0; i < word.length(); i++) {
    char lowercased_letter = tolower(word[i]);

    if (lowercased_letter == 32) {
      decryped_word += lowercased_letter;
      continue;
    }

    int index_letter = hash[lowercased_letter];
    int new_letter_index = (index_letter - k + 26) % 26;
    decryped_word += letters[new_letter_index];
  }

  return decryped_word;
}

int main() {
  int k = 10;
  std::string word;
  std::cout << "Frase para encriptograr: " << std::endl;
  std::getline(std::cin, word);

  std::string encryped_word = encrypt(word, k);
  std::string decryped_word = decrypt(encryped_word, k);

  std::cout << "Palavra encriptografada " << encryped_word << std::endl;
  std::cout << "Palavra decriptografada " << decryped_word << std::endl;
  return 0;
}
