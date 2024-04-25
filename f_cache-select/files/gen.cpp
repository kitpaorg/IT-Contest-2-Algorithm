#include "testlib.h"
using namespace std;

int A[202020];

#define bb ' '
#define ln '\n'

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	auto N = opt<int>("N");
	auto M = opt<int>("M");
	auto K = opt<int>("K");
	auto X = opt<int>("X");
	auto Y = opt<int>("Y");
	auto Bmax = opt<int>("Bmax");
	auto Bmin = opt<int>("Bmin");
	auto per = opt<int>("permutation");
	if (!N) N = rnd.next(1, 200'000);
	if (!M) M = rnd.next(1, 200'000);
	if (!K) K = rnd.next(1, 1'000'000);
	if (!X) X = rnd.next(1, 1'000'000);
	if (!Y) Y = rnd.next(1, 1'000'000);
	if (X >= Y) {
		Y = X + 1;
		if (Y > 1'000'000) X--, Y--;
	}

	if (per) M = N;

	cout << N << bb << M << bb << K << bb << X << bb << Y << ln;

	int i;
	if (per) {
		for (i = 1; i <= N; i++) A[i] = i;
		for (i = N; i >= 1; i--) swap(A[i], A[rnd.next(1, i)]);
		for (i = 1; i <= N; i++) {
			cout << A[i];
			if (i == N) cout << ln;
			else cout << bb;
		}
	}
	else {
		for (i = 1; i <= M; i++) {
			cout << rnd.next(1, N);
			if (i == M) cout << ln;
			else cout << bb;
		}
	}
	for (i = 1; i <= N; i++) {
		cout << rnd.next(Bmin, Bmax);
		if (i == N) cout << ln;
		else cout << bb;
	}
}
