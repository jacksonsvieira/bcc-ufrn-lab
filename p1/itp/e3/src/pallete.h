#include <iostream>
#include <fstream>

struct Color {
    u_int8_t r;
    u_int8_t g;
    u_int8_t b;
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

        void loadFromFile(const std::string filePath);

};