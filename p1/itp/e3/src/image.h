#include <iostream>
#include <fstream>
#include "pallete.h"

class Image {
    int width, height;
    Color *pixels = nullptr;

    public:
        Image(int width, int height);
        ~Image();

        Color getColor(int y, int x);
        void setColor(int y, int x, const Color &new_color);

        int saveToPPM(const std::string &filePath);
};