#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../doctest.h"
#include "string_maluca.cpp"


TEST_CASE("Testing hello world function"){
    CHECK(wordToCamelCase("hello") == "Hello");
}

TEST_CASE("Testing hello world function"){
    CHECK(toCamelCase("hello World") == "HelloWorld");
}