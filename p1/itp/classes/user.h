#include <iostream>

using std::string;

using std::cout;
using std::endl;

class Usuario {
private:
  string userName;

public:
  Usuario(string name) { userName = name; };
  void getName() { cout << userName << endl; }
};
