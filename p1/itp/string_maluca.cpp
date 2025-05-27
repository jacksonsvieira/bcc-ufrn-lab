#include <iostream>
#include <string>

using namespace std;

string wordToCamelCase(string word){
    char ch = word[0];
    return char(toupper(ch)) + word.substr(1, word.size());
}

string toCamelCase(string line){
    string camelCased = "";

    // TODO: Tem como utilizar o find para pegar os espacos em branco
    int start = 0;
    int end = 0;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ' '){
            camelCased = camelCased + wordToCamelCase(line.substr(start, end));
            start = i+1;
        }
        end++;
    }


    return camelCased;
}