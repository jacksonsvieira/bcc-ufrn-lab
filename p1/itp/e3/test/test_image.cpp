#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/image.h"


bool checkEveryAllSameColor(
    Image &image, 
    const Color &color,
    int width,
    int height
){
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            Color pixel_color = image.getColor(i, k);
            if (pixel_color.r == color.r && pixel_color.g == color.g && pixel_color.b == color.b) continue;
            return false;
        }
    }

    return true;
}

TEST_CASE("Tests initialization") {
    const int IMAGE_WIDTH = 2;
    const int IMAGE_HEIGHT = 2;

    auto my_image = Image(IMAGE_WIDTH, IMAGE_HEIGHT);

    CHECK(checkEveryAllSameColor(my_image, {0, 0, 0}, IMAGE_WIDTH, IMAGE_HEIGHT));
}

TEST_CASE("Tests setColor and getColor") {
    const int IMAGE_WIDTH = 4;
    const int IMAGE_HEIGHT = 3;

    auto my_image = Image(IMAGE_HEIGHT, IMAGE_WIDTH);

    for (int i = 0; i < IMAGE_HEIGHT; i++)
    {
        for (int k = 0; k < IMAGE_WIDTH; k++)
        {
            my_image.setColor(i, k, {255, 255, 255});
        }
    }

    CHECK(checkEveryAllSameColor(my_image, {255, 255, 255,}, IMAGE_WIDTH, IMAGE_HEIGHT));
}

TEST_CASE("Tests save Image to a file") {

}