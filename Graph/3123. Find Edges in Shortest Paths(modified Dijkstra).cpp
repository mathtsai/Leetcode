class Solution {
public:
    #define N 50001
    vector<bool> mark;
    vector<pair<int,int>> ancestor[N];
    bool vis[N];

    void dfs(int u)
    {
        if(vis[u]) return;
        vis[u] = true;
        for(auto &[v,num]: ancestor[u])
        {
            mark[num] = true;
            dfs(v);
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& E) {
        //init
        vector<pair<int,int>> g[n];
        int m = E.size();
        mark.resize(m);
        for(int i=0; i<m; i++)
        {
            int u = E[i][0], v = E[i][1];
            g[u].push_back({v,i});
            g[v].push_back({u,i});
        }

        //Dijkstra
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        bool vis[n];
        long long dis[n];
        for(int i=0; i<n; i++)
        {
            vis[i] = false;
            dis[i] = 1e12;
        }

        dis[0] = 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [val,u] = pq.top();
            pq.pop();

            if(vis[u]) continue;
            vis[u] = true;

            for(auto &[v, num]: g[u])
            {
                int w = E[num][2];
                if(dis[v] > dis[u]+w)
                {
                    dis[v] = dis[u]+w;
                    ancestor[v].clear();
                    ancestor[v].push_back({u,num});
                    pq.push({dis[v], v});
                }
                else if(dis[v] == dis[u]+w)
                    ancestor[v].push_back({u,num});
            }
        }

        dfs(n-1);
        return mark;
    }
};
