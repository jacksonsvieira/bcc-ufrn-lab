#include "map.h"

int main(){
    Palette my_palette;
    my_palette.loadFromFile("./colors_gray.txt");

    int n = 10;
    auto minimap = HeightMap(n);
    minimap.generate(0.5);
    auto minimap_image = minimap.toImage(my_palette);
    minimap_image.saveToPPM("./results/minimap_gray_shadow.ppm");

    return 0;
}