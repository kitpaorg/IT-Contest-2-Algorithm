/*
* Problem cache-select
* h3
*
* Validator
*/

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
#define bb ' '
#define ln '\n'
#define Ln '\n'
#define MAXN 200'000
#define MAXM 200'000
#define MOD 998'244'353
#define MAXV 1'000'000
int A[MAX];
int B[MAX];
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(1, MAXN, "N");
	inf.readSpace();
	int M = inf.readInt(1, MAXM, "M");
	inf.readSpace();
	int K = inf.readInt(1, MAXV, "K");
	inf.readSpace();
	int X = inf.readInt(1, MAXV, "X");
	inf.readSpace();
	int Y = inf.readInt(X + 1, MAXV, "Y");
	inf.readEoln();
	int i;
	for (i = 1; i <= M; i++) {
		inf.readInt(1, N, "A_i");
		if (i == M) inf.readEoln();
		else inf.readSpace();
	}
	for (i = 1; i <= N; i++) {
		inf.readInt(0, MAXV, "B_i");
		if (i == N) inf.readEoln();
		else inf.readSpace();
	}
	inf.readEof();
}