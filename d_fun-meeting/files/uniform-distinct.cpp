#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto T = opt<int>("T");
  vector<pair<int, int>> AB(N);
  for (auto &[ai, bi] : AB) {
    ai = rnd.next(0, T);
    bi = rnd.next(0, T - 1);
    if (bi >= ai)
      bi++;
    if (ai > bi)
      swap(ai, bi);
  }
  vector<pair<int, int>> CD;
  for (auto i : rnd.distinct(M, (long long)N * (N - 1) / 2)) {
    auto d = (long long)sqrt(i);
    while (d * (d - 1) / 2 <= i)
      d++;
    auto c = d * (d - 1) / 2 - i;
    CD.emplace_back(c, d);
  }
  println(N, M, T);
  for (auto [ai, bi] : AB)
    println(ai, bi);
  for (auto [c, d] : CD)
    println(c, d);
}
