#include<bits/stdc++.h>
using namespace std;

//only support for point update
class segment_tree {
    vector<int> t;

public:
    segment_tree(int n)
    {
        t.resize(4*(n+1)+1);
    }

    //point update
    void update(int id, int s, int e, int val)
    {
        if(s == e)
        {
            t[id] += 1;
            return;
        }
        int m = (s+e) >> 1;

        if(val <= m)
            update(id<<1, s, m, val);
        if(val > m)
            update(id<<1 | 1, m+1, e, val);

        t[id] = t[id<<1] + t[id<<1 | 1];
    }

    int query(int id, int s, int e, int qs, int qe)
    {
        if(qs>e || qe<s) return 0;
        if(qs<=s && e<=qe) return t[id];
        int m = (s+e) >> 1;
        return query(id<<1, s, m, qs, qe) + query(id<<1 | 1, m+1, e, qs, qe);
    }
};

//315. Count of Smaller Numbers After Self
//link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        a[i] += 10000;
    }

    int N = 20000; //max(a[i]) - min(a[i])
    segment_tree T(N);
    for(int i=n-1; i>=0; i--)
    {
        cout << T.query(1,0,N,0,a[i]-1) << '\n';
        T.update(1,0,N,a[i]);
    }
}

