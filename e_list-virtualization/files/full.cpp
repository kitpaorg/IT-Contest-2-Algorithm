#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto Hmax = opt<int>("Hmax");
  auto Hmin = opt<int>("Hmin");
  auto A = opt<int>("A");
  auto B = opt<int>("B");
  auto C = opt<int>("C");
  auto Q = A + B + C;
  vector<int> H(N);
  for (auto &Hi : H)
    Hi = rnd.next(Hmin, Hmax);
  vector<int> Op(Q);
  for (auto i : rnd.distinct(Q, Q)) {
    if (A) {
      Op[i] = 1;
      A--;
    } else if (B) {
      Op[i] = 2;
      B--;
    } else if (C) {
      Op[i] = 3;
      C--;
    }
  }
  println(N, Q);
  println(H);
  auto count = N;
  for (auto op : Op) {
    int i, h;
    switch (op) {
    case 1:
      i = rnd.next(1, ++count);
      h = rnd.next(Hmin, Hmax);
      println(op, i, h);
      break;
    case 2:
      i = rnd.next(1, count--);
      println(op, i);
      break;
    case 3:
      println(op, 0, (long long)Hmax * count);
      break;
    }
  }
}
