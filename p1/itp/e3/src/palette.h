#include <cstdint>
#include <string>

struct Color {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

class Palette {
    private:
        static const int MAX_COLORS = 100;
        int quantity;
        Color colors[MAX_COLORS];
        float values[MAX_COLORS];

    public:
        Palette();

        Palette(
            int quantity,
            Color inputColors[],
            float inputValues[]
        );

        int getQuantity();
        Color getColor(float value) const;

        int loadFromFile(const std::string &filePath);

        void print();
};