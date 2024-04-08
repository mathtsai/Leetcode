#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> p,sz;

public:
    DSU(int n)
    {
        p.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    //~DSU() by default

    int Find(int x)
    {
        //path compression
        return (x == p[x]) ? x : p[x] = Find(p[x]);
    }

    void Union(int x, int y)
    {
        int px = Find(x);
        int py = Find(y);

        if(px == py) return;

        //union by size
        if(sz[px] < sz[py]) swap(px,py);
        p[py] = px;
        sz[px] += sz[py];
        sz[py] = 0;
    }
};

int main()
{
    DSU d(5);
    d.Union(0,1);
    d.Union(0,2);
    for(int i=0; i<5; i++)
        cout << d.Find(i) << '\n';
}

