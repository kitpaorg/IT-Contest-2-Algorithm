#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  auto N = inf.readInt(1, 200'000, "N");
  inf.readSpace();
  auto Q = inf.readInt(1, 200'000, "Q");
  inf.readEoln();
  auto H = inf.readInts(N, 1, 1'000'000'000, "H");
  inf.readEoln();
  auto elemCount = N;
  for (int i = 0; i < Q; ++i) {
    auto op = inf.readInt(1, 3, "op");
    switch (op) {
    case 1: {
      inf.readSpace();
      auto i = inf.readInt(1, elemCount + 1, "i");
      inf.readSpace();
      auto h = inf.readInt(1, 1'000'000'000, "h");
      elemCount++;
    } break;
    case 2: {
      inf.readSpace();
      auto i = inf.readInt(1, elemCount, "i");
      elemCount--;
    } break;
    case 3: {
      inf.readSpace();
      auto t = inf.readLong(0LL, 400'000'000'000'000LL - 1, "t");
      inf.readSpace();
      auto b = inf.readLong(t + 1, 400'000'000'000'000LL, "b");
    } break;
    }
    inf.readEoln();
  }
  inf.readEof();
}
