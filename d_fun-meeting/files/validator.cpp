#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  auto N = inf.readInt(2, 200'000, "N");
  inf.readSpace();
  auto M = inf.readInt(1, 200'000, "M");
  inf.readSpace();
  auto T = inf.readInt(1, 200'000, "T");
  inf.readEoln();
  for (int i = 0; i < N; ++i) {
    auto ai = inf.readInt(0, T - 1, "ai");
    inf.readSpace();
    auto bi = inf.readInt(ai + 1, T, "bi");
    inf.readEoln();
  }
  set<pair<int, int>> relation;
  for (int i = 0; i < M; ++i) {
    auto c = inf.readInt(1, N - 1, "c");
    inf.readSpace();
    auto d = inf.readInt(c + 1, N, "d");
    ensuref(relation.count({c, d}) == 0, "duplicated relation");
    inf.readEoln();
    relation.emplace(c, d);
  }
  inf.readEof();
}
