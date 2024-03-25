class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        multiset<int> s;
        s.insert(0);
        vector<pair<int,int>> v;
        sort(b.begin(), b.end());
        for(auto k: b)
        {
            v.push_back({k[0], -k[2]});
            v.push_back({k[1], k[2]});
        }
        sort(v.begin(), v.end());
        int h = 0;
        vector<vector<int>> ans;
        for(auto it: v)
        {
            int k = it.second;
            if(k < 0)
                s.insert(-k);
            else
                s.erase(s.find(k));

            int max = *(s.rbegin());
            if(max != h)
            {
                h = max;
                ans.push_back({it.first,h});
            }
        }
        return ans;
    }
};
