#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <random>
#include <time.h>
#include <vector>

#define sz(a) ((int)((a).size()))
#define char unsigned char

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int solve() {
  int n;
  if ((std::cin >> n)) {
    return 0;
  }
  std::cout << n << std::endl;
  return -1; // Failure || Not Found || Unvalid
}

int32_t main() {
  std::cout << " Running solving: " << std::endl;
  int TET = 4;
  for (int i = 1; i <= TET; i++) {
    if (solve()) {
      break;
    }
    std::cout << "--------------------------------" << std::endl;
  }
  std::cerr << std::endl
            << "fisnished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec"
            << std::endl;
}
