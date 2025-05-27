#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "hello_world.cpp"


TEST_CASE("Testing hello world function"){
    CHECK(helloWorld("Jackson") == "Hello, Jackson");
}