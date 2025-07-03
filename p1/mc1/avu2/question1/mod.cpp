#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

// a = bq + r -> b > 0
// r > 0 e r < |b|

int customAbs(int b) {
  if (b < 0) {
    b = -b;
  }

  return b;
}

int customMod(int a, int b) {
  int abs_b = customAbs(b);
  int r = a;
  int q = 0;

  if (b == 0) {
    return a;
  }

  if (a > 0) {
    while (r >= abs_b) {
      r -= abs_b;
      q++;
    }
  }

  if (a < 0) {
    while (r < 0) {   
      r += abs_b;
      q--;
    }
  }

  if (b < 0) {
    q = -q;
  }

  return r;
}

TEST_CASE("Div function") {
  CHECK(customMod(5, 2) == 1);
  CHECK(customMod(-5, -2) == 1);
  CHECK(customMod(16, 2) == 0);
  CHECK(customMod(2, -2) == 0);
  CHECK(customMod(8, -1) == 0);
  CHECK(customMod(-2, 1) == 0);
  CHECK(customMod(-7, 3) == 2);
  CHECK(customMod(10, 0) == 10);
}
