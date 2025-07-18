#include <iostream>
#include <fstream>
#include "palette.h"

class Image {
    int width, height;
    Color *pixels = nullptr;

    public:
        /**
         * Constructs an Image object with the given width and height.
         * @param width The width of the image
         * @param height The height of the image
         */
        Image(int width, int height);
        /**
         * Destroys the Image object and frees memory.
         */
        ~Image();

        /**
         * Returns the color at the specified position.
         * @param y The row index
         * @param x The column index
         * @return The color at (y, x)
         */
        Color getColor(int y, int x);
        /**
         * Sets the color at the specified position.
         * @param y The row index
         * @param x The column index
         * @param new_color The new color to set at (y, x)
         */
        void setColor(int y, int x, const Color &new_color);

        /**
         * Saves the image to a PPM (P3) file.
         * @param filePath The path to the .ppm file to save
         * @return 0 if successful, nonzero otherwise
         */
        int saveToPPM(const std::string &filePath);
};