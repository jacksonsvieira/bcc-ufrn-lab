#include <iostream>
#include <fstream>

#include "pallete.h"

Palette::Palette(){
    quantity = 0;
}

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

void Palette::loadFromFile(const std::string filePath) {

    std::ifstream file(filePath);
    // TODO: handle expceptions like cannot read the file


    file >> quantity;

    for (int i = 0; i < quantity; ++i) {
        int val;
        Color c;
        file >> val >> (int&)c.r >> (int&)c.g >> (int&)c.b;
        values[i] = val;
        colors[i] = c;
    }
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