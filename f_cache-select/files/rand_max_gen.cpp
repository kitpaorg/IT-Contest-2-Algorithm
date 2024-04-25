#include <bits/stdc++.h>
#include "testlib.h"
#include <cassert>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define MAX 301010
#define MAXS 20
#define INF 1000000000000000001
#define bb ' '
#define ln '\n'
#define Ln '\n'
#define MAXV 1'000'000
#define MOD 998244353
int A[MAX];
vector<pii> edges;
int p[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	int M = atoi(argv[3]);
	int K, X, Y;
	K = MAXV;
	X = MAXV - 1;
	Y = MAXV;

	cout << N << bb << M << bb << K << bb << X << bb << Y << ln;

	int i;
	for (i = 1; i <= M; i++) {
		cout << rnd.next(1, N);
		if (i == M) cout << ln;
		else cout << bb;
	}

	for (i = 1; i <= N; i++) {
		cout << MAXV;
		if (i == N) cout << ln;
		else cout << bb;
	}
}
