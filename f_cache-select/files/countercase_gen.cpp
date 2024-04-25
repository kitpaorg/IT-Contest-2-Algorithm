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
int p[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	int M = atoi(argv[3]);
	assert(N + 2 <= M);
	cout << N << bb << M << bb << 1 << bb << 1 << bb << MAXV << ln;
	deque<int> dq;
	int i;
	dq.push_back(rnd.next(1, N - 1));
	for (i = 1; i <= N; i++) dq.push_back(i);
	dq.push_back(rnd.next(2, N));
	for (i = 1; i <= N; i++) p[i] = i;
	for (i = N; i >= 1; i--) swap(p[i], p[rnd.next(1, i)]);
	while (dq.size() < M) {
		if (rnd.next(1, 2) <= 1) {
			int x = dq.back();
			dq.pop_back();
			int y = dq.back();
			dq.push_back(x);
			int v;
			if (x != y) v = rnd.next(1, 3) == 1 ? x : y;
			else v = rnd.next(1, N);
			dq.push_back(v);
		}
		else {
			int x = dq.front();
			dq.pop_front();
			int y = dq.front();
			dq.push_front(x);
			int v;
			if (x != y) v = rnd.next(1, 3) == 1 ? x : y;
			else v = rnd.next(1, N);
			dq.push_front(v);
		}
	}
	i = 0;
	for (auto x : dq) {
		cout << p[x];
		i++;
		if (i == M) cout << ln;
		else cout << bb;
	}
	for (i = 1; i <= N; i++) {
		cout << rnd.next(1, MAXV);
		if (i == N) cout << ln;
		else cout << bb;
	}
}
