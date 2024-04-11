#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int n,a;
    n=inf.readInt(1,100'000,"n");
    a=inf.readInt(1,n,"a");
    string s,tmp(n,'0');
    s=inf.readToken("[01]+","s");
    set<pair<int,int>>S;
    auto flip=[&](int i)
    {
        if(s[i]=='0')s[i]='1';
        else s[i]='0';
    };
    for(int i=1;i<n;i++)
    {
        int u,v;
        u=inf.readInt(1,n-1,"x");
        v=inf.readInt(u+1,n,"y");
        S.emplace(u,v);
        S.emplace(v,u);
    }
    int k=ouf.readInt(0,4*n,"k");
    auto op=ouf.readInts(k,1,n,"ui");
    for(int i=0;i<k;i++)
    {
        if(!S.count(pair{a,op[i]}))quitf(_wa,"wa did not go through tree edge");
        flip(a-1);a=op[i];
    }
    if(s!=tmp)quitf(_wa,"something is not turned off");
    quitf(_ok,"ok AC");
}
