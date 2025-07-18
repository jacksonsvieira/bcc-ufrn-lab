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
        /**
         * Constructs an empty Palette object.
         */
        Palette();

        /**
         * Constructs a Palette with the given colors and values.
         * @param quantity The number of colors
         * @param inputColors The array of colors
         * @param inputValues The array of values for each color
         */
        Palette(
            int quantity,
            Color inputColors[],
            float inputValues[]
        );

        /**
         * Returns the number of colors in the palette.
         * @return The number of colors
         */
        int getQuantity();
        /**
         * Returns the color corresponding to the given value.
         * @param value The value to map to a color
         * @return The corresponding color in a interval of values
         */
        Color getColor(float value) const;

        /**
         * Loads the palette from a file.
         * @param filePath The path to the palette file
         * @return 0 if successful, nonzero otherwise
         */
        int loadFromFile(const std::string &filePath);

        /**
         * A utility function to print the palette to the standard output.
         */
        void print();
};