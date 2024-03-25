class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& v) {
        sort(f.begin(), f.end());
        int n = f.size();

        map<int,int> m;
        for(int i=0; i<n; i++)
        {
            m[f[i][0]]++;
            m[f[i][1]+1]--;
        }

        int cnt = 0;
        vector<vector<int>> flower;
        flower.push_back({0,0});
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            int pos = it->first;
            cnt += it->second;
            flower.push_back({pos,cnt});
        }
        flower.push_back({(int)1e9+1,0});

        n = flower.size();
        vector<int> ans;
        int k = v.size();
        for(int i=0; i<k; i++)
        {
            int l=0, h=n-2;
            while(l<=h)
            {
                int M = (l+h)/2;

                if(v[i] < flower[M+1][0] && v[i] >= flower[M][0])
                {
                    ans.push_back(flower[M][1]);
                    break;
                }
                if(v[i] > flower[M][0])
                    l = M+1;
                else
                    h = M-1;
            }
        }
        return ans;
    }
};
