#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto T = opt<int>("T");
  auto E = rnd.distinct(N * 2, 0, T);
  vector<pair<int, int>> AB;
  for (int i = 0; i < N; ++i) {
    auto ai = E[i * 2];
    auto bi = E[i * 2 + 1];
    if (ai > bi)
      swap(ai, bi);
    AB.emplace_back(ai, bi);
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
