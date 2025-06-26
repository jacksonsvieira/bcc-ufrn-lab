#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int customAbs(int b) {
  if (b < 0) {
    b = -b;
  }

  return b;
}

int customDiv(int a, int b) {
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
  CHECK(customDiv(10, 2) == 0);
  CHECK(customDiv(5, 2) == 1);
  CHECK(customDiv(16, 2) == 0);
  CHECK(customDiv(2, -2) == 0);
  CHECK(customDiv(8, -1) == 0);
  CHECK(customDiv(-2, 1) == 0);
  CHECK(customDiv(-7, 3) == 2);

  CHECK(customDiv(10, 0) == 10);
}
