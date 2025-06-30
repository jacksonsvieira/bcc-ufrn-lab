#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

// n = x + f
// x >= 0 (dado 0 < f < 1 logo n < x < n+1)
// ceil -> n < x < n+1
int ceil(int x) {
  int n = 0;
  while (true) {
    if (x < 0) {
      if (n - 1 < x) {
        return n;
      }
      n--;
    } else {
      if (n + 1 > x) {
        return n;
      }
      n++;
    }
  }
}

TEST_CASE("Ceil function") {
  CHECK(ceil(2.5) == 3);
  CHECK(ceil(2.0) == 2);
  CHECK(ceil(0.5) == 1);
  CHECK(ceil(0.0) == 0);
  CHECK(ceil(-1.5) == -1);
  CHECK(ceil(-1.0) == -1);
}
