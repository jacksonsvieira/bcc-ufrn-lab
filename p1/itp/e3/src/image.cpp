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
    return 0;
}