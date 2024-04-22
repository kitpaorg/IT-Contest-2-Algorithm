#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto Hmax = opt<int>("Hmax");
  auto Hmin = opt<int>("Hmin");
  auto i = opt<int>("i");
  auto t = opt<long long>("t");
  auto b = opt<long long>("b");
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
    switch (op) {
    case 1:
      println(op, i, rnd.next(Hmin, Hmax));
      count++;
      break;
    case 2:
      println(op, i);
      count--;
      break;
    case 3:
      println(op, t, b);
      break;
    }
  }
}
