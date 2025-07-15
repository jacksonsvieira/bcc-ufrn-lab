#include <iostream>
#include <fstream>

struct Color {
    u_int8_t r = 0;
    u_int8_t g = 0;
    u_int8_t b = 0;
};

class Palette {
    private:
        static const int MAX_COLORS = 100;
        int quantity;
        Color colors[MAX_COLORS];
        int values[MAX_COLORS];

    public:
        Palette();

        Palette(
            int quantity,
            Color inputColors[],
            int inputValues[]
        );

        int getQuantity();
        Color getColor(int value);

        int loadFromFile(const std::string &filePath);

};