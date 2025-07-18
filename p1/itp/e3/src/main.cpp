#include "map.h"
#include <iostream>

int main(){
    Palette original_palette, gray_palette, brazil_palette;

    original_palette.loadFromFile("./colors.txt");
    gray_palette.loadFromFile("./colors_gray.txt");
    brazil_palette.loadFromFile("./colors_brazil.txt");

    int n = 10;

    std::cout << "Enter the size of the minimap (Ex. 10): ";
    std::cin >> n;

    auto minimap = HeightMap(n);
    minimap.generate(0.5);

    auto original_image = minimap.toImage(original_palette);
    auto original_image_with_shadow = minimap.toImage(original_palette, true);

    original_image.saveToPPM("./results/minimap_original.ppm");
    original_image_with_shadow.saveToPPM("./results/minimap_original_shadow.ppm");

    auto gray_image = minimap.toImage(gray_palette);
    auto gray_image_with_shadow = minimap.toImage(gray_palette, true);

    gray_image.saveToPPM("./results/minimap_gray.ppm");
    gray_image_with_shadow.saveToPPM("./results/minimap_gray_shadow.ppm");

    auto brazil_image = minimap.toImage(brazil_palette);
    auto brazil_image_with_shadow = minimap.toImage(brazil_palette, true);

    brazil_image.saveToPPM("./results/minimap_brazil.ppm");
    brazil_image_with_shadow.saveToPPM("./results/minimap_brazil_shadow.ppm");

    return 0;
}