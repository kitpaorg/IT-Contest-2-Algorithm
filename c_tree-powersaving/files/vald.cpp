#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> ret(par.size());
        for (int i = 0; i < int(par.size()); ++i) ret[find(i)].push_back(i);
        ret.erase(std::remove_if(ret.begin(), ret.end(),
                                 [&](const std::vector<int> &v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};
 
int main(int argc,char*argv[])
{
    registerValidation(argc,argv);
    int n=inf.readInt(2,100'000,"n");
    inf.readSpace();
    inf.readInt(1,n,"a");
    inf.readEoln();
    auto s=inf.readLine("[01]+","s");
    ensuref((int)s.size()==n,"string length = n");
    UnionFind UF(n);
    for(int i=1;i<n;i++)
    {
        int a=inf.readInt(1,n-1,"x");
        inf.readSpace();
        int b=inf.readInt(a+1,n,"y");
        inf.readEoln();
        a--;b--;
        UF.unite(a,b);
    }
    ensuref(UF.count(0)==n,"is tree");
    inf.readEof();
}
