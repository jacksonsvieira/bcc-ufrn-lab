#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

// n = x + f
// x >= 0 (dado 0 < f < 1 logo n < x < n+1)
// ceil -> n < x < n+1
int floor(float x) {
  int n = 0;
  while (true) {
    if (n == x)
      return n;

    if (x < 0) {
      if (n < x) {
        return n;
      }
      n--;
    } else if (x > 0) {
      if (n > x) {
        return n;
      }
      n++;
    }
  }
}

TEST_CASE("Floor function") {
  CHECK(floor(2.5) == 2);
  CHECK(floor(2.0) == 2);
  CHECK(floor(0.5) == 0);
  CHECK(floor(0.0) == 0);
  CHECK(floor(-1.5) == -2);
  CHECK(floor(-1.0) == -1);
};
