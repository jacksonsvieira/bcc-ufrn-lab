// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

// #include "../src/palette.h"

// TEST_CASE("Tests to pallete using class constructor") {
//     Color inputColors[] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};
//     float inputValues[] = {0.f, 10.f, 30.f};

//     auto my_palette = Palette(3, inputColors, inputValues);

//     // red
//     Color expected_color = {255, 0, 0};
//     Color result_color = my_palette.getColor(5);

//     CHECK(result_color.r == expected_color.r);
//     CHECK(result_color.g == expected_color.g);
//     CHECK(result_color.b == expected_color.b);

//     // green
//     expected_color = {0, 255, 0};
//     result_color = my_palette.getColor(10);

//     CHECK(result_color.r == expected_color.r);
//     CHECK(result_color.g == expected_color.g);
//     CHECK(result_color.b == expected_color.b);

//     // blue
//     expected_color = {0, 0, 255};
//     result_color = my_palette.getColor(35);

//     CHECK(result_color.r == expected_color.r);
//     CHECK(result_color.g == expected_color.g);
//     CHECK(result_color.b == expected_color.b);
// }

// TEST_CASE("Tests to pallete initializing with a file stream") {
//     auto my_palette = Palette();

//     const std::string FILE_PATH = "./test/data/palette.txt";

//     my_palette.loadFromFile(FILE_PATH);

//     CHECK(my_palette.getQuantity() == 2);
// }