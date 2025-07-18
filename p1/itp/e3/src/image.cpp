#include <iostream>
#include <fstream>

#include "image.h"

Image::Image(int width, int height){
    this->height = height;
    this->width = width;
    pixels = new Color[height*width];
}

Image::~Image(){
    delete[] pixels;
}

Color Image::getColor(int y, int x){
    int index = y * width + x;
    return pixels[index];
}

void Image::setColor(int y, int x, const Color &new_color){
    int index = y * width + x;
    pixels[index] = new_color;
}

int Image::saveToPPM(const std::string &filePath){
    std::ofstream out(filePath);

    out << "P3" << "\n";
    out << width << " " << height << "\n";
    out << 255 << "\n";

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Color color = getColor(y, x);
            out << static_cast<int>(color.r) << " "
                << static_cast<int>(color.g) << " "
                << static_cast<int>(color.b) << " ";            
        }
        out << "\n";
    }

    return 0;
}