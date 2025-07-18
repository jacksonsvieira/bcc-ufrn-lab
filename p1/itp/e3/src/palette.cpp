#include <iostream>
#include <fstream>
#include <algorithm>

#include "palette.h"

Palette::Palette(){
    quantity = 0;
}

Palette::Palette(
    int inputQuantity,
    Color inputColors[],
    float inputValues[]
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
        float val;
        int r, g, b;
        if (!(file >> val >> r >> g >> b)) {
            std::cerr << "Erro na linha " << (i+1) << "\n";
            break;
        }

        values[i]       = val;
        colors[i].r     = static_cast<uint8_t>(r);
        colors[i].g     = static_cast<uint8_t>(g);
        colors[i].b     = static_cast<uint8_t>(b);
    }

    file.close();
    return 0;
}

// TODO: Make tests
Color Palette::getColor(float value) const {
    value = std::clamp(value, 0.0f, 1.0f);

    if (quantity <= 1)
        return colors[0];
    int idx = 0;
    for (int i = 1; i < quantity; ++i) {
        if (value < values[i]) {
            break;
        }
        idx = i;
    }

    return colors[idx];
}

int Palette::getQuantity(){
    return quantity;
}

void Palette::print() {
    std::cout << "Palette: " << quantity << " colors\n";
    for (int i = 0; i < quantity; ++i) {
        std::cout << "Color " << i << ": "
                  << static_cast<int>(colors[i].r) << ", "
                  << static_cast<int>(colors[i].g) << ", "
                  << static_cast<int>(colors[i].b) << " (Value: " 
                  << values[i] << ")\n";
    }
}