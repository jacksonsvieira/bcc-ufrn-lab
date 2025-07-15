#include <iostream>
#include <fstream>

#include "pallete.h"

Palette::Palette(){
    quantity = 0;
}

// TODO: Otimizar parametros por referencia para evitar overload da memoria.

Palette::Palette(
    int inputQuantity,
    Color inputColors[],
    int inputValues[]
) {
    this->quantity = inputQuantity;

    for (int i = 0; i < quantity; i++)
    {
        colors[i] = inputColors[i];
        values[i] = inputValues[i];
    }
    
}

int Palette::loadFromFile(const std::string &filePath) {

    std::ifstream file(filePath);

    if(!file.is_open()){
        std::cerr << "Error: Unable to open file!" << std::endl;
        return 1;
    }

    file >> quantity;

    for (int i = 0; i < quantity; ++i) {
        int val;
        Color c;
        file >> val >> (int&)c.r >> (int&)c.g >> (int&)c.b;
        values[i] = val;
        colors[i] = c;
    }

    file.close();
    return 0;
}

Color Palette::getColor(int value) {
    int index = 0;

    while(value >= values[index] && index < quantity){
        index++;
    }

    return colors[index-1];
}

int Palette::getQuantity(){
    return quantity;
}