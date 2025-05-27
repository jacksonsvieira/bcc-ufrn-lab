#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../doctest.h"
#include "discover_triangulo.cpp"


TEST_CASE("DeveRetornar0CasoEquilatero"){
    CHECK(verificarTriangulo(10.5, 10.5, 10.5) == 0);
}

TEST_CASE("DeveRetornar1CasoIsosceles"){
    CHECK(verificarTriangulo(3.2, 3.2, 4.1) == 1);
    CHECK(verificarTriangulo(5.0, 3.2, 3.2) == 1);
    CHECK(verificarTriangulo(3.2, 3.1, 3.2) == 1);
}

TEST_CASE("DeveRetornar2CasoTrianguloEscaleno"){
    CHECK(verificarTriangulo(3.2, 4.9, 4.1) == 2);
    CHECK(verificarTriangulo(5.0, 3.1, 2.9) == 2);
    CHECK(verificarTriangulo(5.0, 3.1, 2.0) == 2);
}

TEST_CASE("DeveRetornar3SeNaoForTriangulo"){
    CHECK(verificarTriangulo(-1.0, 3.2, 5.4) == 3);
    CHECK(verificarTriangulo(-1.0, 3.2, 5.4) == 3);
    CHECK(verificarTriangulo(5, 3.1, 0) == 3);
    CHECK(verificarTriangulo(1.1, 4.5, 2.7) == 3);
}