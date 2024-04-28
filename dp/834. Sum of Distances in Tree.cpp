class Solution {
public:
    #define N 30001
    bool vis[N];
    int cnt[N];
    vector<int> g[N];
    vector<int> dis;

    void init(int n, vector<vector<int>>& E)
    {
        dis.resize(n,0);
        for(int i=0; i<n; i++)
            cnt[i] = 1;
        for(auto &k: E)
        {
            int u = k[0], v = k[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void dfs(int k, int d)
    {
        vis[k] = true;
        dis[0] += d;
        for(auto &next: g[k])
        {
            if(!vis[next])
            {
                dfs(next, d+1);
                cnt[k] += cnt[next];
            }
        }
        vis[k] = false;
    }

    void Dis(int k, int parent, int n)
    {
        vis[k] = true;
        if(k != 0)
            dis[k] = dis[parent]+(n-2*cnt[k]);

        for(auto &next: g[k])
        {
            if(!vis[next])
                Dis(next, k, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& E) {
        init(n, E);
        dfs(0,0);
        Dis(0,0,n);
        return dis;
    }
};
